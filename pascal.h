int read_size();
int max_element(int **arr, int sz);
int digits(int number);
void init_pascal(int **arr, int sz);
void print_pascal(int **arr, int sz);
void destroy_pascal(int **arr, int sz);

// Returns the maximum element of a pascal's triangle of size sz
int max_element(int **arr, int sz) 
{
    if(sz == 1) return 1;
    int i = sz - 1;
    int j = i/2;
    return arr[i][j];
}

// Returns the number of digits in a non-negative integer
int digits(int number)
{
    if(number == 0) return 1;
    int ans = 0;
    while(number != 0)
    {
        number /= 10;
        ans++;
    }
    return ans;
}

// initializes a pascal triangle of size sz into a 2D array
void init_pascal(int **arr, int sz)
{
    for(int i = 0; i < sz; i++)
    {
        arr[i] = malloc(sizeof(int) * (i+1));
    }
    arr[0][0] = 1;
    for(int i = 1; i < sz; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(j == 0 || j == i) arr[i][j] = 1;
            else arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
        }
    }
}

// prints a pascal triangle of size sz with proper formatting
void print_pascal(int **arr, int sz)
{
    int max_digits = digits(max_element(arr, sz));
    for(int i = 0; i < sz; i++)
    {
        int k = (max_digits + 1)/2 + 1;
        for(int j = 0; j < k * (sz - i - 1); j++) printf(" ");
        for(int j = 0; j <= i; j++)
        {
            int spaces = max_digits + 1;
            if(spaces % 2 == 0) spaces++;
            int cur = 10;
            while(cur <= arr[i][j])
            {
                spaces--;
                cur *= 10;
            }
            printf("%d", arr[i][j]);
            for(int i = 0; i < spaces; i++) printf(" ");
        }
        printf("\n");
    }
}

// frees memory of a pascal's triangle
void destroy_pascal(int **arr, int sz)
{
    for(int i = 0; i < sz; i++) 
    {
        free(arr[i]);
    }
    free(arr);
}

// reads one integer from the user and stores it
int read_size()
{
    int input = 0;
    printf("What size Pascal Triangle do you want?\n");
    if(scanf("%d", &input) != 1) return -1;
    return input;
}
