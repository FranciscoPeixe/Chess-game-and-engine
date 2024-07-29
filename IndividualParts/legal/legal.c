void legal(char board[8][8])
{
    if(moves % 2 == 0)
    {
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                if(board[i][j] != toupper(board[i][j]))//a board tem uma peca preta
                {
                    legalBlackKing(board, i, j);
                    legalBlackKnight(board, i, j);
                    legalBlackBishop(board, i, j);
                    legalBlackRook(board, i, j);
                    legalBlackPawn(board, i, j);
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
                    legalWhiteKing(board, i, j);
                    legalWhiteKnight(board, i, j);
                    legalWhiteBishop(board, i, j);
                    legalWhiteRook(board, i, j);
                    legalWhitePawn(board, i, j);
                }
            }
        }
    }
}

void legalBlackKing(char board[8][8], int i, int j)
{
    if(board[i][j] == 'r')
    {
        for(int a = -1; a < 2; a++)
        {
            for(int b = -1; b < 2; b++)
            {
                if(board[i+a][j+b] == toupper(board[i+a][j+b]) || board[i+a][j+a] == ' ')
                {
                    if(board[i+a][j+b] == 'R')
                    {
                        illegalMove = 1;
                    }
                } 
            }
        }
    }
}

void legalBlackKnight(char board[8][8], int i, int j)
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
                        if(board[i+a][j+b] == 'R')
                        {
                            illegalMove = 1;
                        }
                    }
                }
            }
        }
    }
}

void legalBlackBishop(char board[8][8], int i, int j)
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
                    if(board[i+c][j+d] == 'R')
                    {
                        illegalMove = 1;
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
                                if(board[i+c*a][j+d*a] == 'R')
                                {
                                    illegalMove = 1;
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

void legalBlackRook(char board[8][8], int i, int j)
{
    if(board[i][j] == 't' || board[i][j] == 'd')
    {
        for(int z = -1; z < 2; z+=2)
        {
            if(board[i+z][j] == toupper(board[i+z][j]) && board[i+z][j] != ' ')
            {
                if(board[i+z][j] == 'R')
                {
                    illegalMove = 1;
                }
            }
            for(int a = 2; board[i+z*(a-1)][j] == ' ' && a <= 7; a++)
            {
                if(board[i+z*a][j] != ' ')
                {
                    if(board[i+z*a][j] == toupper(board[i+z*a][j]))
                    {
                        if(board[i+z*a][j] == 'R')
                        {
                            illegalMove = 1;
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
                if(board[i][j+z] == 'R')
                {
                    illegalMove = 1;
                }
            }
            for(int a = 2; board[i][j+z*(a-1)] == ' ' && a <= 7; a++)
            {
                if(board[i][j+z*a] != ' ')
                {
                    if(board[i][j+z*a] == toupper(board[i][j+z*a]))
                    {
                        if(board[i][j+z*a] == 'R')
                        {
                            illegalMove = 1;
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

void legalBlackPawn(char board[8][8], int i, int j)
{
    if(board[i][j] == 'p')
    {
        for(int a = -1; a < 2; a += 2)
        {
            if(board[i+1][j+a*1] == toupper(board[i+1][j+a*1]) && board[i+1][j+a*1]  != ' ')
            {
                if(board[i+1][j+1*a] == 'R')
                {
                    illegalMove = 1;
                }
            }
        }
    }
}

void legalWhiteKing(char board[8][8], int i, int j)
{
    if(board[i][j] == 'R')
    {
        for(int a = -1; a < 2; a++)
        {
            for(int b = -1; b < 2; b++)
            {
                if(board[i+a][j+b] != toupper(board[i+a][j+b]))
                {
                    if(board[i+a][j+b] == 'r')
                    {
                        illegalMove = 1;
                    }
                } 
            }
        }
    }
}

void legalWhiteKnight(char board[8][8], int i, int j)
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
                        if(board[i+a][j+b] == 'r')
                        {
                            illegalMove = 1;
                        }
                    }
                }
            }
        }
    }
}

void legalWhiteBishop(char board[8][8], int i, int j)
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
                    if(board[i+c][j+d] == 'r')
                    {
                        illegalMove = 1;
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
                                if(board[i+c*a][j+d*a] == 'r')
                                {
                                    illegalMove = 1;
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

void legalWhiteRook(char board[8][8], int i, int j)
{
    if(board[i][j] == 'T' || board[i][j] == 'D')
    {
        for(int z = -1; z < 2; z+=2)
        {
            if(board[i+z][j] != toupper(board[i+z][j]) && board[i+z][j] != ' ')
            {
                if(board[i+z][j] == 'r')
                {
                    illegalMove = 1;
                }
            }
            for(int a = 2; board[i+z*(a-1)][j] == ' ' && a <= 7; a++)
            {
                if(board[i+z*a][j] != ' ')
                {
                    if(board[i+z*a][j] != toupper(board[i+z*a][j]))
                    {
                        if(board[i+z*a][j] == 'r')
                        {
                            illegalMove = 1;
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
                if(board[i][j+z] == 'r')
                {
                    illegalMove = 1;
                }
            }
            for(int a = 2; board[i][j+z*(a-1)] == ' ' && a <= 7; a++)
            {
                if(board[i][j+z*a] != ' ')
                {
                    if(board[i][j+z*a] == toupper(board[i][j+z*a]))
                    {
                        if(board[i][j+z*a] == 'r')
                        {
                            illegalMove = 1;
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

void legalWhitePawn(char board[8][8], int i, int j)
{
    if(board[i][j] == 'P')
    {
        for(int a = -1; a < 2; a += 2)
        {
            if(board[i-1][j+a*1] != toupper(board[i-1][j+a*1]) && board[i-1][j+a*1] != ' ')
            {
                if(board[i-1][j+1*a] == 'r')
                {
                    illegalMove = 1;
                }
            }
        }
    }
}
