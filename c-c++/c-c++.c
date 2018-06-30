#include <stdio.h>

typedef enum {
    NORMAL,//普通状态
    FOUND_SLASH,//遇到'\'
    CPP_COMMENT,//c++注释状态
    C_COMMENT,//c注释状态
    FOUND_STAR//遇到'*'
}State;

int main()
{
    FILE* fin;
    FILE* fout;
    fin = fopen("input.c","r");
    if(fin == NULL)
    {
        perror("fopen");
        return 0;
    }
    fout = fopen("output.c","w");
    if(fout == NULL)
    {
        perror("fopen");
        fclose(fin);
    }
    State state = NORMAL;
    while(1)
    {
        int ch = fgetc(fin);
        if(ch == EOF)
        {
            break;
        }
        switch(state)
        {
            case NORMAL:
                if(ch == '/')
                {
                    state = FOUND_SLASH;
                }
                fputc(ch,fout);
                break;
            case FOUND_SLASH:
                if(ch == '/')
                {
                    fputc(ch,fout);
                    state = CPP_COMMENT;
                }else if(ch == '*')
                {
                    fputc('/',fout);
                    state = C_COMMENT;
                }else
                {
                    fputc(ch,fout);
                    state = NORMAL;
                }
                break;
            case CPP_COMMENT:
                if(ch == '\n')
                {
                    state = NORMAL;
                }
                fputc(ch,fout);
                break;
            case C_COMMENT:
//                if(ch == '\n')
//                {
//                    fputc('\n',fout);
//                    fprintf(fout,"//");
//                    state = NORMAL;
//                }
                if(ch == '*')
                {
                    state = FOUND_STAR;
                }else
                {
                    fputc(ch,fout);
                }
                break;
            case FOUND_STAR:
                if(ch == '/')
                {
//                    int nextch = fgetc(fin);
//                    if(nextch != '\r')
//                    {
//                        fputc('\n',fout);
//                    }
//                    ungetc(nextch,fin);
                    state = NORMAL;
                }else if(ch == '*')
                {
                    fputc('*',fout);
                    state = FOUND_STAR;
                }
                else{
                    fputc('*',fout);
                    state = C_COMMENT;
                }
                break;
        }
    }

    fclose(fout);
    fclose(fin);
    return 0;
}

