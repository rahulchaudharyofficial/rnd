#include "_string.h"


int find(const char *text, const char *str)
{
    int sl = strlen(str);
    int tl = strlen(text);
    bool found = false;
    for(int i = 0; i < (tl-sl+1); i++)
    {
        int j = 0; 
        while(j < sl)
        {
            if(text[i+j]!=str[j])
            {
                break;
            }
            j++;
        }
        if(j==sl)
        {
            found=true;
            return i;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    return EXIT_SUCCESS;
}
