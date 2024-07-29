void engine1(char board[8][8])
{
    AdvantageOponent = 0;
    if(moves % 2 == 1) //foi a jogada das bracas
    {
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                if(board[i][j] != toupper(board[i][j]))//a board tem uma peca preta
                {
                    engine1BlackKing(board, i, j);
                    engine1BlackKnight(board, i, j);
                    engine1BlackBishop(board, i, j);
                    engine1BlackRook(board, i, j);
                    engine1BlackPawn(board, i, j);
                }
            }
        }
    }
    else
    {
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                if(board[i][j] == toupper(board[i][j]))//a board tem uma peca preta
                {
                    engine1WhiteKing(board, i, j);
                    engine1WhiteKnight(board, i, j);
                    engine1WhiteBishop(board, i, j);
                    engine1WhiteRook(board, i, j);
                    engine1WhitePawn(board, i, j);
                }
            }
        }
    }
}

void engine1BlackKing(char board[8][8], int i, int j)
{
    if(board[i][j] == 'r')
    {
        for(int a = -1; a < 2; a++)
        {
            for(int b = -1; b < 2; b++)
            {
                if(board[i+a][j+b] == toupper(board[i+a][j+b]) || board[i+a][j+a] == ' ')
                {
                    switch(board[i+a][j+b])
                    {
                        case 'P':
                            if(AdvantageOponent < 1)
                            {
                                AdvantageOponent = 1;
                            }
                            break;
                        case 'C':
                            if(AdvantageOponent < 3)
                            {
                                AdvantageOponent = 3;
                            }
                            break;
                        case 'B':
                            if(AdvantageOponent < 3)
                            {
                                AdvantageOponent = 3;
                            }
                            break;
                        case 'T':
                            if(AdvantageOponent < 5)
                            {
                                AdvantageOponent = 5;
                            }
                            break;
                        case 'D':
                            if(AdvantageOponent < 9)
                            {
                                AdvantageOponent = 9;
                            }
                            break;
                        default:
                            AdvantageOponent = AdvantageOponent;
                            break;
                    }
                } 
            }
        }
    }
}

void engine1BlackKnight(char board[8][8], int i, int j)
{
    if(board[i][j] == 'c')
    {
        for(int a = -2; a < 3; a++)
        {
            if(a == 0)
            {
                continue;
            }
            else
            {
                for(int b = -2; b < 3; b++)
                {
                    if((b == 0)||(abs(b) == 2 && abs(a) == 2)||(abs(b) == 1 && abs(a) == 1))
                    {
                        continue;
                    }
                    else
                    {
                        switch(board[i+a][j+b])
                        {
                            case 'P':
                                if(AdvantageOponent < 1)
                                {
                                    AdvantageOponent = 1;
                                }
                                break;
                            case 'C':
                                if(AdvantageOponent < 3)
                                {
                                    AdvantageOponent = 3;
                                }
                                break;
                            case 'B':
                                if(AdvantageOponent < 3)
                                {
                                    AdvantageOponent = 3;
                                }
                                break;
                            case 'T':
                                if(AdvantageOponent < 5)
                                {
                                    AdvantageOponent = 5;
                                }
                                break;
                            case 'D':
                                if(AdvantageOponent < 9)
                                {
                                    AdvantageOponent = 9;
                                }
                                break;
                            default:
                                AdvantageOponent = AdvantageOponent;
                                break;             
                        }
                    }
                }
            }
        }
    }
}

void engine1BlackBishop(char board[8][8], int i, int j)
{
    if(board[i][j] == 'b' || board[i][j] == 'd')
    {
        for(int c = -1; c < 2; c+=2)
        {
            for(int d = -1; d < 2; d+=2)
            {
                int squaresAVerificarVertical = 0;
                int squaresAVerificarHorizontal  = 0;
                if(c == 1)
                {
                    squaresAVerificarVertical = 7-i;
                }
                else
                {
                    squaresAVerificarVertical = i;
                }
                if(d == 1)
                {
                    squaresAVerificarHorizontal = 7-j;
                }
                else
                {
                    squaresAVerificarHorizontal = j;
                }
                if(board[i+c][j+d] == toupper(board[i+c][j+d]) && board[i+c][j+d] != ' ')
                {
                    switch(board[i+c][j+d])
                    {
                        case 'P':
                            if(AdvantageOponent < 1)
                            {
                                AdvantageOponent = 1;
                            }
                            break;
                        case 'C':
                            if(AdvantageOponent < 3)
                            {
                                AdvantageOponent = 3;
                            }
                            break;
                        case 'B':
                            if(AdvantageOponent < 3)
                            {
                                AdvantageOponent = 3;
                            }
                            break;
                        case 'T':
                            if(AdvantageOponent < 5)
                            {
                                AdvantageOponent = 5;
                            }
                            break;
                        case 'D':
                            if(AdvantageOponent < 9)
                            {
                                AdvantageOponent = 9;
                            }
                            break;
                        default:
                            AdvantageOponent = AdvantageOponent;
                            break;
                    }
                }
                else
                {
                    for(int a = 2; board[i+c*(a-1)][j+d*(a-1)] == ' ' && a >=2 && a <= squaresAVerificarHorizontal && a <= squaresAVerificarVertical; a++)
                    {
                        if(board[i+c*a][j+d*a] != ' ')//diagonal esquerda e cima
                        {
                            if(board[i+c*a][j+d*a] == toupper(board[i+c*a][j+d*a]))
                            {
                                switch(board[i+c*a][j+d*a])
                                {
                                    case 'P':
                                        if(AdvantageOponent < 1)
                                        {
                                            AdvantageOponent = 1;
                                        }
                                        break;
                                    case 'C':
                                        if(AdvantageOponent < 3)
                                        {
                                            AdvantageOponent = 3;
                                        }
                                        break;
                                    case 'B':
                                        if(AdvantageOponent < 3)
                                        {
                                            AdvantageOponent = 3;
                                        }
                                        break;
                                    case 'T':
                                        if(AdvantageOponent < 5)
                                        {
                                            AdvantageOponent = 5;
                                        }
                                        break;
                                    case 'D':
                                        if(AdvantageOponent < 9)//verworwoifica se a vantagem anterior era menor
                                        {
                                            AdvantageOponent = 9;
                                        }
                                        break;
                                    default:
                                        AdvantageOponent = AdvantageOponent;
                                        break;
                                }
                            }
                            else
                            {
                                break;
                            }
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
            }
        }
    }    
}

void engine1BlackRook(char board[8][8], int i, int j)
{
    if(board[i][j] == 't' || board[i][j] == 'd')
    {
        for(int z = -1; z < 2; z+=2)
        {
            if(board[i+z][j] == toupper(board[i+z][j]) && board[i+z][j] != ' ')
            {
                switch(board[i+z][j])
                {
                    case 'P':
                        if(AdvantageOponent < 1)
                        {
                            AdvantageOponent = 1;
                        }
                        break;
                    case 'C':
                        if(AdvantageOponent < 3)
                        {
                            AdvantageOponent = 3;
                        }
                        break;
                    case 'B':
                        if(AdvantageOponent < 3)
                        {
                            AdvantageOponent = 3;
                        }
                        break;
                    case 'T':
                        if(AdvantageOponent < 5)
                        {
                            AdvantageOponent = 5;
                        }
                        break;
                    case 'D':
                        if(AdvantageOponent < 9)
                        {
                            AdvantageOponent = 9;
                        }
                        break;
                    default:
                        AdvantageOponent = AdvantageOponent;
                        break;
                }
            }
            for(int a = 2; board[i+z*(a-1)][j] == ' ' && a <= 7; a++)
            {
                if(board[i+z*a][j] != ' ')
                {
                    if(board[i+z*a][j] == toupper(board[i+z*a][j]))
                    {
                        switch(board[i+z*a][j])
                        {
                            case 'P':
                                if(AdvantageOponent < 1)
                                {
                                    AdvantageOponent = 1;
                                }
                                break;
                            case 'C':
                                if(AdvantageOponent < 3)
                                {
                                    AdvantageOponent = 3;
                                }
                                break;
                            case 'B':
                                if(AdvantageOponent < 3)
                                {
                                    AdvantageOponent = 3;
                                }
                                break;
                            case 'T':
                                if(AdvantageOponent < 5)
                                {
                                    AdvantageOponent = 5;
                                }
                                break;
                            case 'D':
                                if(AdvantageOponent < 9)
                                {
                                    AdvantageOponent = 9;
                                }
                                break;
                            default:
                                AdvantageOponent = AdvantageOponent;
                                break;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    continue;
                }
            }
        }

        for(int z = -1; z < 2; z+=2)
        {
            if(board[i][j+z] == toupper(board[i][j+z]) && board[i][j+z] != ' ')
            {
                switch(board[i][j+z])
                {
                    case 'P':
                        if(AdvantageOponent < 1)
                        {
                            AdvantageOponent = 1;
                        }
                        break;
                    case 'C':
                        if(AdvantageOponent < 3)
                        {
                            AdvantageOponent = 3;
                        }
                        break;
                    case 'B':
                        if(AdvantageOponent < 3)
                        {
                            AdvantageOponent = 3;
                        }
                        break;
                    case 'T':
                        if(AdvantageOponent < 5)
                        {
                            AdvantageOponent = 5;
                        }
                        break;
                    case 'D':
                        if(AdvantageOponent < 9)
                        {
                            AdvantageOponent = 9;
                        }
                        break;
                    default:
                        AdvantageOponent = AdvantageOponent;
                        break;
                }
            }
            for(int a = 2; board[i][j+z*(a-1)] == ' ' && a <= 7; a++)
            {
                if(board[i][j+z*a] != ' ')
                {
                    if(board[i][j+z*a] == toupper(board[i][j+z*a]))
                    {
                        switch(board[i][j+z*a])
                        {
                            case 'P':
                                if(AdvantageOponent < 1)
                                {
                                    AdvantageOponent = 1;
                                }
                                break;
                            case 'C':
                                if(AdvantageOponent < 3)
                                {
                                    AdvantageOponent = 3;
                                }
                                break;
                            case 'B':
                                if(AdvantageOponent < 3)
                                {
                                    AdvantageOponent = 3;
                                }
                                break;
                            case 'T':
                                if(AdvantageOponent < 5)
                                {
                                    AdvantageOponent = 5;
                                }
                                break;
                            case 'D':
                                if(AdvantageOponent < 9)
                                {
                                    AdvantageOponent = 9;
                                }
                                break;
                            default:
                                AdvantageOponent = AdvantageOponent;
                                break;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    continue;
                }
            }
        }
    }
}

void engine1BlackPawn(char board[8][8], int i, int j)
{
    if(board[i][j] == 'p')
    {
        for(int a = -1; a < 2; a += 2)
        {
            if(board[i+1][j+a*1] == toupper(board[i+1][j+a*1]) && board[i+1][j+a*1]  != ' ')
            {
                switch(board[i+1][j+1*a])
                {
                    case 'P':
                        if(AdvantageOponent < 1)
                        {
                            AdvantageOponent = 1;
                        }
                        break;
                    case 'C':
                        if(AdvantageOponent < 3)
                        {
                            AdvantageOponent = 3;
                        }
                        break;
                    case 'B':
                        if(AdvantageOponent < 3)
                        {
                            AdvantageOponent = 3;
                        }
                        break;
                    case 'T':
                        if(AdvantageOponent < 5)
                        {
                            AdvantageOponent = 5;
                        }
                        break;
                    case 'D':
                        if(AdvantageOponent < 9)
                        {
                            AdvantageOponent = 9;
                        }
                        break;
                    default:
                        AdvantageOponent = AdvantageOponent;
                        break;
                }
            }
        }
    }
}

void engine1WhiteKing(char board[8][8], int i, int j)
{
    if(board[i][j] == 'R')
    {
        for(int a = -1; a < 2; a++)
        {
            for(int b = -1; b < 2; b++)
            {
                if(board[i+a][j+b] != toupper(board[i+a][j+b]))
                {
                    switch(board[i+a][j+b])
                    {
                        case 'p':
                            if(AdvantageOponent < 1)
                            {
                                AdvantageOponent = 1;
                            }
                            break;
                        case 'c':
                            if(AdvantageOponent < 3)
                            {
                                AdvantageOponent = 3;
                            }
                            break;
                        case 'b':
                            if(AdvantageOponent < 3)
                            {
                                AdvantageOponent = 3;
                            }
                            break;
                        case 't':
                            if(AdvantageOponent < 5)
                            {
                                AdvantageOponent = 5;
                            }
                            break;
                        case 'd':
                            if(AdvantageOponent < 9)
                            {
                                AdvantageOponent = 9;
                            }
                            break;
                        default:
                            AdvantageOponent = AdvantageOponent;
                            break;
                    }
                } 
            }
        }
    }
}

void engine1WhiteKnight(char board[8][8], int i, int j)
{
    if(board[i][j] == 'C')
    {
        for(int a = -2; a < 3; a++)
        {
            if(a == 0)
            {
                continue;
            }
            else
            {
                for(int b = -2; b < 3; b++)
                {
                    if((b == 0)||(abs(b) == 2 && abs(a) == 2)||(abs(b) == 1 && abs(a) == 1))
                    {
                        continue;
                    }
                    else
                    {
                        switch(board[i+a][j+b])
                        {
                            case 'p':
                                if(AdvantageOponent < 1)
                                {
                                    AdvantageOponent = 1;
                                }
                                break;
                            case 'c':
                                if(AdvantageOponent < 3)
                                {
                                    AdvantageOponent = 3;
                                }
                                break;
                            case 'b':
                                if(AdvantageOponent < 3)
                                {
                                    AdvantageOponent = 3;
                                }
                                break;
                            case 't':
                                if(AdvantageOponent < 5)
                                  {
                                    AdvantageOponent = 5;
                                }
                                break;
                            case 'd':
                                if(AdvantageOponent < 9)
                                {
                                    AdvantageOponent = 9;
                                }
                                break;
                            default:
                                AdvantageOponent = AdvantageOponent;
                                break;
                        }
                    }
                }
            }
        }
    }
}

void engine1WhiteBishop(char board[8][8], int i, int j)
{
    if(board[i][j] == 'B' || board[i][j] == 'D')
    {
        for(int c = -1; c < 2; c+=2)
        {
            for(int d = -1; d < 2; d+=2)
            {
                int squaresAVerificarVertical = 0;
                int squaresAVerificarHorizontal  = 0;
                if(c == 1)
                {
                    squaresAVerificarVertical = 7-i;
                }
                else
                {
                    squaresAVerificarVertical = i;
                }
                if(d == 1)
                {
                    squaresAVerificarHorizontal = 7-j;
                }
                else
                {
                    squaresAVerificarHorizontal = j;
                }
                if(board[i+c][j+d] != toupper(board[i+c][j+d]) && board[i+c][j+d] != ' ')
                {
                    switch(board[i+c][j+d])
                    {
                        case 'p':
                            if(AdvantageOponent < 1)
                            {
                                AdvantageOponent = 1;
                            }
                            break;
                        case 'c':
                            if(AdvantageOponent < 3)
                            {
                                AdvantageOponent = 3;
                            }
                            break;
                        case 'b':
                            if(AdvantageOponent < 3)
                            {
                                AdvantageOponent = 3;
                            }
                            break;
                        case 't':
                            if(AdvantageOponent < 5)
                            {
                                AdvantageOponent = 5;
                            }
                            break;
                        case 'd':
                            if(AdvantageOponent < 9)
                            {
                                AdvantageOponent = 9;
                            }
                            break;
                        default:
                            AdvantageOponent = AdvantageOponent;
                            break;
                    }
                }
                else
                {
                    for(int a = 2; board[i+c*(a-1)][j+d*(a-1)] == ' ' && a >=2 && a <= squaresAVerificarHorizontal && a <= squaresAVerificarVertical; a++)
                    {
                        if(board[i+c*a][j+d*a] != ' ')//diagonal esquerda e cima
                        {
                            if(board[i+c*a][j+d*a] != toupper(board[i+c*a][j+d*a]))
                            {
                                switch(board[i+c*a][j+d*a])
                                {
                                    case 'p':
                                        if(AdvantageOponent < 1)
                                        {
                                            AdvantageOponent = 1;
                                        }
                                        break;
                                    case 'c':
                                        if(AdvantageOponent < 3)
                                        {
                                            AdvantageOponent = 3;
                                        }
                                        break;
                                    case 'b':
                                        if(AdvantageOponent < 3)
                                        {
                                            AdvantageOponent = 3;
                                        }
                                        break;
                                    case 't':
                                        if(AdvantageOponent < 5)
                                        {
                                            AdvantageOponent = 5;
                                        }
                                        break;
                                    case 'd':
                                        if(AdvantageOponent < 9)
                                        {
                                            AdvantageOponent = 9;
                                        }
                                        break;
                                    default:
                                        AdvantageOponent = AdvantageOponent;
                                        break;
                                }
                            }
                            else
                            {
                                break;
                            }
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
            }
        }
    } 
}

void engine1WhiteRook(char board[8][8], int i, int j)
{
    if(board[i][j] == 'T' || board[i][j] == 'D')
    {
        for(int z = -1; z < 2; z+=2)
        {
            if(board[i+z][j] != toupper(board[i+z][j]) && board[i+z][j] != ' ')
            {
                switch(board[i+z][j])
                {
                    case 'p':
                        if(AdvantageOponent < 1)
                        {
                            AdvantageOponent = 1;
                        }
                        break;
                    case 'c':
                        if(AdvantageOponent < 3)
                        {
                            AdvantageOponent = 3;
                        }
                        break;
                    case 'b':
                        if(AdvantageOponent < 3)
                        {
                            AdvantageOponent = 3;
                        }
                        break;
                    case 't':
                        if(AdvantageOponent < 5)
                        {
                            AdvantageOponent = 5;
                        }
                        break;
                    case 'd':
                        if(AdvantageOponent < 9)
                        {
                            AdvantageOponent = 9;
                        }
                        break;
                    default:
                        AdvantageOponent = AdvantageOponent;
                        break;
                }
            }
            for(int a = 2; board[i+z*(a-1)][j] == ' ' && a <= 7; a++)
            {
                if(board[i+z*a][j] != ' ')
                {
                    if(board[i+z*a][j] != toupper(board[i+z*a][j]))
                    {
                        switch(board[i+z*a][j])
                        {
                            case 'p':
                                if(AdvantageOponent < 1)
                                {
                                    AdvantageOponent = 1;
                                }                           
                                break;
                            case 'c':
                                if(AdvantageOponent < 3)
                                {
                                    AdvantageOponent = 3;
                                }
                                break;
                            case 'b':
                                if(AdvantageOponent < 3)
                                {
                                    AdvantageOponent = 3;
                                }
                                break;
                            case 't':
                                if(AdvantageOponent < 5)
                                {
                                    AdvantageOponent = 5;
                                }
                                break;
                            case 'd':
                                if(AdvantageOponent < 9)
                                {
                                    AdvantageOponent = 9;
                                }
                                break;
                            default:
                                AdvantageOponent = AdvantageOponent;
                                break;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    continue;
                }
            }
        }

        for(int z = -1; z < 2; z+=2)
        {
            if(board[i][j+z] != toupper(board[i][j+z]) && board[i][j+z] != ' ')
            {
                switch(board[i][j+z])
                {
                    case 'p':
                        if(AdvantageOponent < 1)
                        {
                            AdvantageOponent = 1;
                        }
                        break;
                    case 'c':
                        if(AdvantageOponent < 3)
                        {
                            AdvantageOponent = 3;
                        }
                        break;
                    case 'b':
                        if(AdvantageOponent < 3)
                        {
                            AdvantageOponent = 3;
                        }
                        break;
                    case 't':
                        if(AdvantageOponent < 5)
                        {
                            AdvantageOponent = 5;
                        }
                        break;
                    case 'd':
                        if(AdvantageOponent < 9)
                        {
                            AdvantageOponent = 9;
                        }
                        break;
                    default:
                        AdvantageOponent = AdvantageOponent;
                        break;
                }
            }
            for(int a = 2; board[i][j+z*(a-1)] == ' ' && a <= 7; a++)
            {
                if(board[i][j+z*a] != ' ')
                {
                    if(board[i][j+z*a] == toupper(board[i][j+z*a]))
                    {
                        switch(board[i][j+z*a])
                        {
                            case 'p':
                                if(AdvantageOponent < 1)
                                {
                                    AdvantageOponent = 1;
                                }
                                break;
                            case 'c':
                                if(AdvantageOponent < 3)
                                {
                                    AdvantageOponent = 3;
                                }
                                break;
                            case 'b':
                                if(AdvantageOponent < 3)
                                {
                                    AdvantageOponent = 3;
                                }
                                break;
                            case 't':
                                if(AdvantageOponent < 5)
                                {
                                    AdvantageOponent = 5;
                                }
                                break;
                            case 'd':
                                if(AdvantageOponent < 9)
                                {
                                    AdvantageOponent = 9;
                                }
                                break;
                            default:
                                AdvantageOponent = AdvantageOponent;
                                break;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    continue;
                }
            }
        }
    }
}

void engine1WhitePawn(char board[8][8], int i, int j)
{
    if(board[i][j] == 'P')
    {
        for(int a = -1; a < 2; a += 2)
        {
            if(board[i-1][j+a*1] != toupper(board[i-1][j+a*1]) && board[i-1][j+a*1] != ' ')
            {
                switch(board[i-1][j+1*a])
                {
                    case 'p':
                        if(AdvantageOponent < 1)
                        {
                            AdvantageOponent = 1;
                        }
                        break;
                    case 'c':
                        if(AdvantageOponent < 3)
                        {
                            AdvantageOponent = 3;
                        }
                        break;
                    case 'b':
                        if(AdvantageOponent < 3)
                        {
                            AdvantageOponent = 3;
                        }
                        break;
                    case 't':
                        if(AdvantageOponent < 5)
                        {
                            AdvantageOponent = 5;
                        }
                        break;
                    case 'd':
                        if(AdvantageOponent < 9)
                        {
                            AdvantageOponent = 9;
                        }
                        break;
                    default:
                        AdvantageOponent = AdvantageOponent;
                        break;
                }
            }
        }
    }
}
