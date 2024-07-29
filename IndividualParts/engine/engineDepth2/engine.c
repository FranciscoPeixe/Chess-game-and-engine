void engine(char board[8][8])
{
    AdvantageOponent = 0;
    vant = 0;
    diferenceInAdvantage = -100;
    if(moves % 2 == 0) //foi a jogada das bracas
    {
        whiteAdvantage = 0;
        blackAdvantage = 0;
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                if(board[i][j] != toupper(board[i][j]))//a board tem uma peca preta
                {
                    engineBlackKing(board, i, j);
                    engineBlackKnight(board, i, j);
                    engineBlackBishop(board, i, j);
                    engineBlackRook(board, i, j);
                    engineBlackPawn(board, i, j);
                }
                /*
                if(board[i][j] == 'P')
                {
                    whiteAdvantage += vantPeao[i][j]; 
                }
                if(board[i][j] == 'p')
                {
                    blackAdvantage += vantPeao[7-i][j]; 
                }
                if(board[i][j] == 'C')
                {
                    whiteAdvantage += vantCavalo[i][j]; 
                }
                if(board[i][j] == 'c')
                {
                    blackAdvantage += vantCavalo[7-i][j]; 
                }
                if(board[i][j] == 'B')
                {
                    whiteAdvantage += vantBispo[i][j];
                }
                if(board[i][j] == 'b')
                {
                    blackAdvantage += vantBispo[7-i][j];
                }
                if(board[i][j] == 'T')
                {
                    whiteAdvantage += vantTorre[i][j];
                }
                if(board[i][j] == 't')
                {
                    blackAdvantage += vantTorre[7-i][j];
                }
                if(board[i][j] == 'D')
                {
                    whiteAdvantage += vantDama[i][j];
                }
                if(board[i][j] == 'd')
                {
                    blackAdvantage += vantDama[7-i][j];
                }
                if(board[i][j] == 'R')
                {
                    whiteAdvantage += vantRei[i][j];
                }
                if(board[i][j] == 'r')
                {
                    blackAdvantage += vantRei[7-i][j];
                }
                */
            }
        }
    }
    else
    {
        blackAdvantage = 0;
        whiteAdvantage = 0;
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                if(board[i][j] == toupper(board[i][j]))//a board tem uma peca preta
                {
                    engineWhiteKing(board, i, j);
                    engineWhiteKnight(board, i, j);
                    engineWhiteBishop(board, i, j);
                    engineWhiteRook(board, i, j);
                    engineWhitePawn(board, i, j);
                }
                /*
                if(board[i][j] == 'P')
                {
                    whiteAdvantage += vantPeao[i][j]; 
                }
                if(board[i][j] == 'p')
                {
                    blackAdvantage += vantPeao[7-i][j];
                }
                if(board[i][j] == 'C')
                {
                    whiteAdvantage += vantCavalo[i][j]; 
                }
                if(board[i][j] == 'c')
                {
                    blackAdvantage += vantCavalo[7-i][j]; 
                }
                if(board[i][j] == 'B')
                {
                    whiteAdvantage += vantBispo[i][j];
                }
                if(board[i][j] == 'b')
                {
                    blackAdvantage += vantBispo[7-i][j];
                }
                if(board[i][j] == 'T')
                {
                    whiteAdvantage += vantTorre[i][j];
                }
                if(board[i][j] == 't')
                {
                    blackAdvantage += vantTorre[7-i][j];
                }
                if(board[i][j] == 'D')
                {
                    whiteAdvantage += vantDama[i][j];
                }
                if(board[i][j] == 'd')
                {
                    blackAdvantage += vantDama[7-i][j];
                }
                if(board[i][j] == 'R')
                {
                    whiteAdvantage += vantRei[i][j];
                }
                if(board[i][j] == 'r')
                {
                    blackAdvantage += vantRei[7-i][j];
                }
                */
            }
        }
    }
}

void engineBlackKing(char board[8][8], int i, int j)
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
                            board[i+a][j+b] = 'r';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'r';
                            board[i+a][j+b] = 'P';
                            if(vant - AdvantageOponent > diferenceInAdvantage)
                            {
                                diferenceInAdvantage = vant - AdvantageOponent;
                                blackAdvantage = vant;
                                whiteAdvantage = AdvantageOponent;
                            }
                            break;
                        case 'C':
                            vant = 3;
                            board[i+a][j+b] = 'r';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'r';
                            board[i+a][j+b] = 'C';
                            if(vant - AdvantageOponent > diferenceInAdvantage)
                            {
                                diferenceInAdvantage = vant - AdvantageOponent;
                                blackAdvantage = vant;
                                whiteAdvantage = AdvantageOponent;
                            }
                            break;
                        case 'B':
                            vant = 3;
                            board[i+a][j+b] = 'r';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'r';
                            board[i+a][j+b] = 'B';
                            if(vant - AdvantageOponent > diferenceInAdvantage)
                            {
                                diferenceInAdvantage = vant - AdvantageOponent;
                                blackAdvantage = vant;
                                whiteAdvantage = AdvantageOponent;
                            }
                            break;
                        case 'T':
                            vant = 5;
                            board[i+a][j+b] = 'r';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'r';
                            board[i+a][j+b] = 'T';
                            if(vant - AdvantageOponent > diferenceInAdvantage)
                            {
                                diferenceInAdvantage = vant - AdvantageOponent;
                                blackAdvantage = vant;
                                whiteAdvantage = AdvantageOponent;
                            }
                            break;
                        case 'D':
                            vant = 9;
                            board[i+a][j+b] = 'r';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'r';
                            board[i+a][j+b] = 'D';
                            if(vant - AdvantageOponent > diferenceInAdvantage)
                            {
                                diferenceInAdvantage = vant - AdvantageOponent;
                                blackAdvantage = vant;
                                whiteAdvantage = AdvantageOponent;
                            }
                            break;
                        case ' ':
                            vant = 0;
                            board[i+a][j+b] = 'r';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'r';
                            board[i+a][j+b] = ' ';
                            if(vant - AdvantageOponent > diferenceInAdvantage)
                            {
                                diferenceInAdvantage = vant - AdvantageOponent;
                                blackAdvantage = vant;
                                whiteAdvantage = AdvantageOponent;
                            }
                            break;
                        default:
                            diferenceInAdvantage = diferenceInAdvantage;
                            break; 
                    }
                } 
            }
        }
    }
}

void engineBlackKnight(char board[8][8], int i, int j)
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
                                vant = 1;
                                board[i+a][j+b] = 'c';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'c';
                                board[i+a][j+b] = 'P';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    blackAdvantage = vant;
                                    whiteAdvantage = AdvantageOponent;
                                }
                                break;
                            case 'C':
                                vant = 3;
                                board[i+a][j+b] = 'c';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'c';
                                board[i+a][j+b] = 'C';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    blackAdvantage = vant;
                                    whiteAdvantage = AdvantageOponent;
                                }
                                break;
                            case 'B':
                                vant = 3;
                                board[i+a][j+b] = 'c';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'c';
                                board[i+a][j+b] = 'B';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    blackAdvantage = vant;
                                    whiteAdvantage = AdvantageOponent;
                                }
                                break;
                            case 'T':
                                vant = 5;
                                board[i+a][j+b] = 'c';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'c';
                                board[i+a][j+b] = 'T';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    blackAdvantage = vant;
                                    whiteAdvantage = AdvantageOponent;
                                }
                                break;
                            case 'D':
                                vant = 9;
                                board[i+a][j+b] = 'c';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'c';
                                board[i+a][j+b] = 'D';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    blackAdvantage = vant;
                                    whiteAdvantage = AdvantageOponent;
                                }
                                break;
                            case ' ':
                                vant = 0;
                                board[i+a][j+b] = 'c';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'c';
                                board[i+a][j+b] = ' ';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    blackAdvantage = vant;
                                    whiteAdvantage = AdvantageOponent;
                                }
                                break; 
                            default:
                                diferenceInAdvantage = diferenceInAdvantage;
                                break;            
                        }
                    }
                }
            }
        }
    }
}

void engineBlackBishop(char board[8][8], int i, int j)
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
                            vant = 1;
                            board[i+c][j+d] = 'b';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'b';
                            board[i+c][j+d] = 'P';
                            if(vant - AdvantageOponent > diferenceInAdvantage)
                            {
                                diferenceInAdvantage = vant - AdvantageOponent;
                                blackAdvantage = vant;
                                whiteAdvantage = AdvantageOponent;
                            }
                            break;
                        case 'C':
                            vant = 3;
                            board[i+c][j+d] = 'b';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'b';
                            board[i+c][j+d] = 'C';
                            if(vant - AdvantageOponent > diferenceInAdvantage)
                            {
                                diferenceInAdvantage = vant - AdvantageOponent;
                                blackAdvantage = vant;
                                whiteAdvantage = AdvantageOponent;
                            }
                            break;
                        case 'B':
                            vant = 3;
                            board[i+c][j+d] = 'b';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'b';
                            board[i+c][j+d] = 'B';
                            if(vant - AdvantageOponent > diferenceInAdvantage)
                            {
                                diferenceInAdvantage = vant - AdvantageOponent;
                                blackAdvantage = vant;
                                whiteAdvantage = AdvantageOponent;
                            }
                            break;
                        case 'T':
                            vant = 5;
                            board[i+c][j+d] = 'b';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'b';
                            board[i+c][j+d] = 'T';
                            if(vant - AdvantageOponent > diferenceInAdvantage)
                            {
                                diferenceInAdvantage = vant - AdvantageOponent;
                                blackAdvantage = vant;
                                whiteAdvantage = AdvantageOponent;
                            }
                            break;
                        case 'D':
                            vant = 9;
                            board[i+c][j+d] = 'b';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'b';
                            board[i+c][j+d] = 'D';
                            if(vant - AdvantageOponent > diferenceInAdvantage)
                            {
                                diferenceInAdvantage = vant - AdvantageOponent;
                                blackAdvantage = vant;
                                whiteAdvantage = AdvantageOponent;
                            }
                            break;
                        case ' ':
                            vant = 0;
                            board[i+c][j+d] = 'b';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'b';
                            board[i+c][j+d] = ' ';
                            if(vant - AdvantageOponent > diferenceInAdvantage)
                            {
                                diferenceInAdvantage = vant - AdvantageOponent;
                                blackAdvantage = vant;
                                whiteAdvantage = AdvantageOponent;
                            }
                            break;
                        default:
                            diferenceInAdvantage = diferenceInAdvantage;
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
                                        vant = 1;
                                        board[i+c*a][j+d*a] = 'b';
                                        board[i][j] = ' ';
                                        engine1(board);
                                        board[i][j] = 'b';
                                        board[i+c*a][j+d*a] = 'P';
                                        if(vant - AdvantageOponent > diferenceInAdvantage)
                                        {
                                            diferenceInAdvantage = vant - AdvantageOponent;
                                            blackAdvantage = vant;
                                            whiteAdvantage = AdvantageOponent;
                                        }
                                        break;
                                    case 'C':
                                        vant = 3;
                                        board[i+c*a][j+d*a] = 'b';
                                        board[i][j] = ' ';
                                        engine1(board);
                                        board[i][j] = 'b';
                                        board[i+c*a][j+d*a] = 'C';
                                        if(vant - AdvantageOponent > diferenceInAdvantage)
                                        {
                                            diferenceInAdvantage = vant - AdvantageOponent;
                                            blackAdvantage = vant;
                                            whiteAdvantage = AdvantageOponent;
                                        }
                                        break;
                                    case 'B':
                                        vant = 3;
                                        board[i+c*a][j+d*a] = 'b';
                                        board[i][j] = ' ';
                                        engine1(board);
                                        board[i][j] = 'b';
                                        board[i+c*a][j+d*a] = 'B';
                                        if(vant - AdvantageOponent > diferenceInAdvantage)
                                        {
                                            diferenceInAdvantage = vant - AdvantageOponent;
                                            blackAdvantage = vant;
                                            whiteAdvantage = AdvantageOponent;
                                        }
                                        break;
                                    case 'T':
                                        vant = 5;
                                        board[i+c*a][j+d*a] = 'b';
                                        board[i][j] = ' ';
                                        engine1(board);
                                        board[i][j] = 'b';
                                        board[i+c*a][j+d*a] = 'T';
                                        if(vant - AdvantageOponent > diferenceInAdvantage)
                                        {
                                            diferenceInAdvantage = vant - AdvantageOponent;
                                            blackAdvantage = vant;
                                            whiteAdvantage = AdvantageOponent;
                                        }
                                        break;
                                    case 'D':
                                        vant = 9;
                                        board[i+c*a][j+d*a] = 'b';
                                        board[i][j] = ' ';
                                        engine1(board);
                                        board[i][j] = 'b';
                                        board[i+c*a][j+d*a] = 'D';
                                        if(vant - AdvantageOponent > diferenceInAdvantage)
                                        {
                                            diferenceInAdvantage = vant - AdvantageOponent;
                                            blackAdvantage = vant;
                                            whiteAdvantage = AdvantageOponent;
                                        }
                                        break;
                                    default:
                                        vant = 0;
                                        board[i+c*a][j+d*a] = 'b';
                                        board[i][j] = ' ';
                                        engine1(board);
                                        board[i][j] = 'b';
                                        board[i+c*a][j+d*a] = ' ';
                                        if(vant - AdvantageOponent > diferenceInAdvantage)
                                        {
                                            diferenceInAdvantage = vant - AdvantageOponent;
                                            blackAdvantage = vant;
                                            whiteAdvantage = AdvantageOponent;
                                        }
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

void engineBlackRook(char board[8][8], int i, int j)
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
                        vant = 1;
                        board[i+z][j] = 't';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 't';
                        board[i+z][j] = 'P';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            blackAdvantage = vant;
                            whiteAdvantage = AdvantageOponent;
                        }
                        break;
                    case 'C':
                        vant = 3;
                        board[i+z][j] = 't';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 't';
                        board[i+z][j] = 'C';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            blackAdvantage = vant;
                            whiteAdvantage = AdvantageOponent;
                        }
                        break;
                    case 'B':
                        vant = 3;
                        board[i+z][j] = 't';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 't';
                        board[i+z][j] = 'B';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            blackAdvantage = vant;
                            whiteAdvantage = AdvantageOponent;
                        }
                        break;
                    case 'T':
                        vant = 5;
                        board[i+z][j] = 't';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 't';
                        board[i+z][j] = 'T';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            blackAdvantage = vant;
                            whiteAdvantage = AdvantageOponent;
                        }
                        break;
                    case 'D':
                        vant = 9;
                        board[i+z][j] = 't';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 't';
                        board[i+z][j] = 'D';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            blackAdvantage = vant;
                            whiteAdvantage = AdvantageOponent;
                        }
                        break;
                    case ' ':
                        vant = 0;
                        board[i+z][j] = 't';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 't';
                        board[i+z][j] = ' ';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            blackAdvantage = vant;
                            whiteAdvantage = AdvantageOponent;
                        }
                        break;
                    default:
                        diferenceInAdvantage = diferenceInAdvantage;
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
                                vant = 1;
                                board[i+z*a][j] = 't';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 't';
                                board[i+z*a][j] = 'P';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    blackAdvantage = vant;
                                    whiteAdvantage = AdvantageOponent;
                                }
                                break;
                            case 'C':
                                vant = 3;
                                board[i+z*a][j] = 't';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 't';
                                board[i+z*a][j] = 'C';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    blackAdvantage = vant;
                                    whiteAdvantage = AdvantageOponent;
                                }
                                break;
                            case 'B':
                                vant = 3;
                                board[i+z*a][j] = 't';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 't';
                                board[i+z*a][j] = 'B';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    blackAdvantage = vant;
                                    whiteAdvantage = AdvantageOponent;
                                }
                                break;
                            case 'T':
                                vant = 5;
                                board[i+z*a][j] = 't';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 't';
                                board[i+z*a][j] = 'T';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    blackAdvantage = vant;
                                    whiteAdvantage = AdvantageOponent;
                                }
                                break;
                            case 'D':
                                vant = 9;
                                board[i+z*a][j] = 't';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 't';
                                board[i+z*a][j] = 'D';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    blackAdvantage = vant;
                                    whiteAdvantage = AdvantageOponent;
                                }
                                break;
                            default:
                                vant = 0;
                                board[i+z*a][j] = 't';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 't';
                                board[i+z*a][j] = ' ';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    blackAdvantage = vant;
                                    whiteAdvantage = AdvantageOponent;
                                }
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
                        vant = 1;
                        board[i][j+z] = 't';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 't';
                        board[i][j+z] = 'P';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            blackAdvantage = vant;
                            whiteAdvantage = AdvantageOponent;
                        }
                        break;
                    case 'C':
                        vant = 3;
                        board[i][j+z] = 't';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 't';
                        board[i][j+z] = 'C';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            blackAdvantage = vant;
                            whiteAdvantage = AdvantageOponent;
                        }
                        break;
                    case 'B':
                        vant = 3;
                        board[i][j+z] = 't';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 't';
                        board[i][j+z] = 'B';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            blackAdvantage = vant;
                            whiteAdvantage = AdvantageOponent;
                        }
                        break;
                    case 'T':
                        vant = 5;
                        board[i][j+z] = 't';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 't';
                        board[i][j+z] = 'T';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            blackAdvantage = vant;
                            whiteAdvantage = AdvantageOponent;
                        }
                        break;
                    case 'D':
                        vant = 9;
                        board[i][j+z] = 't';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 't';
                        board[i][j+z] = 'D';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            blackAdvantage = vant;
                            whiteAdvantage = AdvantageOponent;
                        }
                        break;
                    default:
                        vant = 0;
                        board[i][j+z] = 't';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 't';
                        board[i][j+z] = ' ';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            blackAdvantage = vant;
                            whiteAdvantage = AdvantageOponent;
                        }
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
                                vant = 1;
                                board[i][j+z*a] = 't';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 't';
                                board[i][j+z*a] = 'P';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    blackAdvantage = vant;
                                    whiteAdvantage = AdvantageOponent;
                                }
                                break;
                            case 'C':
                                vant = 3;
                                board[i][j+z*a] = 't';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 't';
                                board[i][j+z*a] = 'C';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    blackAdvantage = vant;
                                    whiteAdvantage = AdvantageOponent;
                                }
                                break;
                            case 'B':
                                vant = 3;
                                board[i][j+z*a] = 't';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 't';
                                board[i][j+z*a] = 'B';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    blackAdvantage = vant;
                                    whiteAdvantage = AdvantageOponent;
                                }
                                break;
                            case 'T':
                                vant = 5;
                                board[i][j+z*a] = 't';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 't';
                                board[i][j+z*a] = 'T';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    blackAdvantage = vant;
                                    whiteAdvantage = AdvantageOponent;
                                }
                                break;
                            case 'D':
                                vant = 9;
                                board[i][j+z*a] = 't';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 't';
                                board[i][j+z*a] = 'D';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    blackAdvantage = vant;
                                    whiteAdvantage = AdvantageOponent;
                                }
                                break;
                            default:
                                vant = 0;
                                board[i][j+z*a] = 't';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 't';
                                board[i][j+z*a] = ' ';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    blackAdvantage = vant;
                                    whiteAdvantage = AdvantageOponent;
                                }
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

void engineBlackPawn(char board[8][8], int i, int j)
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
                        vant = 1;
                        board[i+1][j+1*a] = 'p';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'p';
                        board[i+1][j+1*a] = 'P';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            blackAdvantage = vant;
                            whiteAdvantage = AdvantageOponent;
                        }
                        break;
                    case 'C':
                        vant = 3;
                        board[i+1][j+1*a] = 'p';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'p';
                        board[i+1][j+1*a] = 'C';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            blackAdvantage = vant;
                            whiteAdvantage = AdvantageOponent;
                        }
                        break;
                    case 'B':
                        vant = 3;
                        board[i+1][j+1*a] = 'p';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'p';
                        board[i+1][j+1*a] = 'B';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            blackAdvantage = vant;
                            whiteAdvantage = AdvantageOponent;
                        }
                        break;
                    case 'T':
                        vant = 5;
                        board[i+1][j+1*a] = 'p';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'p';
                        board[i+1][j+1*a] = 'T';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            blackAdvantage = vant;
                            whiteAdvantage = AdvantageOponent;
                        }
                        break;
                    case 'D':
                        vant = 9;
                        board[i+1][j+1*a] = 'p';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'p';
                        board[i+1][j+1*a] = 'D';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            blackAdvantage = vant;
                            whiteAdvantage = AdvantageOponent;
                        }
                        break;
                    case ' ':
                        vant = 0;
                        board[i+1][j+1*a] = 'p';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'p';
                        board[i+1][j+1*a] = ' ';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            blackAdvantage = vant;
                            whiteAdvantage = AdvantageOponent;
                        }
                        break;
                    default:
                        diferenceInAdvantage = diferenceInAdvantage;
                        break; 
                }
            }
        }
    }
}

void engineWhiteKing(char board[8][8], int i, int j)
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
                            vant = 1;
                            board[i+a][j+b] = 'R';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'R';
                            board[i+a][j+b] = 'p';
                            if(vant - AdvantageOponent > diferenceInAdvantage)
                            {
                                diferenceInAdvantage = vant - AdvantageOponent;
                                whiteAdvantage = vant;
                                blackAdvantage = AdvantageOponent;
                            }
                            break;
                        case 'c':
                            vant = 3;
                            board[i+a][j+b] = 'R';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'R';
                            board[i+a][j+b] = 'c';
                            if(vant - AdvantageOponent > diferenceInAdvantage)
                            {
                                diferenceInAdvantage = vant - AdvantageOponent;
                                whiteAdvantage = vant;
                                blackAdvantage = AdvantageOponent;
                            }
                            break;
                        case 'b':
                            vant = 3;
                            board[i+a][j+b] = 'R';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'R';
                            board[i+a][j+b] = 'b';
                            if(vant - AdvantageOponent > diferenceInAdvantage)
                            {
                                diferenceInAdvantage = vant - AdvantageOponent;
                                whiteAdvantage = vant;
                                blackAdvantage = AdvantageOponent;
                            }
                            break;
                        case 't':
                            vant = 5;
                            board[i+a][j+b] = 'R';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'R';
                            board[i+a][j+b] = 't';
                            if(vant - AdvantageOponent > diferenceInAdvantage)
                            {
                                diferenceInAdvantage = vant - AdvantageOponent;
                                whiteAdvantage = vant;
                                blackAdvantage = AdvantageOponent;
                            }
                            break;
                        case 'd':
                            vant = 9;
                            board[i+a][j+b] = 'R';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'R';
                            board[i+a][j+b] = 'd';
                            if(vant - AdvantageOponent > diferenceInAdvantage)
                            {
                                diferenceInAdvantage = vant - AdvantageOponent;
                                whiteAdvantage = vant;
                                blackAdvantage = AdvantageOponent;
                            }
                            break;
                        case ' ':
                            vant = 0;
                            board[i+a][j+b] = 'R';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'R';
                            board[i+a][j+b] = ' ';
                            if(vant - AdvantageOponent > diferenceInAdvantage)
                            {
                                diferenceInAdvantage = vant - AdvantageOponent;
                                whiteAdvantage = vant;
                                blackAdvantage = AdvantageOponent;
                            }
                            break;
                        default:
                                diferenceInAdvantage = diferenceInAdvantage;
                                break; 
                    }
                } 
            }
        }
    }
}

void engineWhiteKnight(char board[8][8], int i, int j)
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
                                vant = 1;
                                board[i+a][j+b] = 'C';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'C';
                                board[i+a][j+b] = 'p';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    whiteAdvantage = vant;
                                    blackAdvantage = AdvantageOponent;
                                }
                                break;
                            case 'c':
                                vant = 3;
                                board[i+a][j+b] = 'C';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'C';
                                board[i+a][j+b] = 'c';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    whiteAdvantage = vant;
                                    blackAdvantage = AdvantageOponent;
                                }
                                break;
                            case 'b':
                                vant = 3;
                                board[i+a][j+b] = 'C';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'C';
                                board[i+a][j+b] = 'b';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    whiteAdvantage = vant;
                                    blackAdvantage = AdvantageOponent;
                                }
                                break;
                            case 't':
                                vant = 5;
                                board[i+a][j+b] = 'C';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'C';
                                board[i+a][j+b] = 't';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    whiteAdvantage = vant;
                                    blackAdvantage = AdvantageOponent;
                                }
                                break;
                            case 'd':
                                vant = 9;
                                board[i+a][j+b] = 'C';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'C';
                                board[i+a][j+b] = 'd';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    whiteAdvantage = vant;
                                    blackAdvantage = AdvantageOponent;
                                }
                                break;
                            case ' ':
                                vant = 0;
                                board[i+a][j+b] = 'C';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'C';
                                board[i+a][j+b] = ' ';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    whiteAdvantage = vant;
                                    blackAdvantage = AdvantageOponent;
                                }
                                break;
                            default:
                                diferenceInAdvantage = diferenceInAdvantage;
                                break; 
                        }
                    }
                }
            }
        }
    }
}

void engineWhiteBishop(char board[8][8], int i, int j)
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
                            vant = 1;
                            board[i+c][j+d] = 'B';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'B';
                            board[i+c][j+d] = 'p';
                            if(vant - AdvantageOponent > diferenceInAdvantage)
                            {
                                diferenceInAdvantage = vant - AdvantageOponent;
                                whiteAdvantage = vant;
                                blackAdvantage = AdvantageOponent;
                            }
                            break;
                        case 'c':
                            vant = 3;
                            board[i+c][j+d] = 'B';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'B';
                            board[i+c][j+d] = 'c';
                            if(vant - AdvantageOponent > diferenceInAdvantage)
                            {
                                diferenceInAdvantage = vant - AdvantageOponent;
                                whiteAdvantage = vant;
                                blackAdvantage = AdvantageOponent;
                            }
                            break;
                        case 'b':
                            vant = 3;
                            board[i+c][j+d] = 'B';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'B';
                            board[i+c][j+d] = 'b';
                            if(vant - AdvantageOponent > diferenceInAdvantage)
                            {
                                diferenceInAdvantage = vant - AdvantageOponent;
                                whiteAdvantage = vant;
                                blackAdvantage = AdvantageOponent;
                            }
                            break;
                        case 't':
                            vant = 5;
                            board[i+c][j+d] = 'B';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'B';
                            board[i+c][j+d] = 't';
                            if(vant - AdvantageOponent > diferenceInAdvantage)
                            {
                                diferenceInAdvantage = vant - AdvantageOponent;
                                whiteAdvantage = vant;
                                blackAdvantage = AdvantageOponent;
                            }
                            break;
                        case 'd':
                            vant = 9;
                            board[i+c][j+d] = 'B';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'B';
                            board[i+c][j+d] = 'd';
                            if(vant - AdvantageOponent > diferenceInAdvantage)
                            {
                                diferenceInAdvantage = vant - AdvantageOponent;
                                whiteAdvantage = vant;
                                blackAdvantage = AdvantageOponent;
                            }
                            break;
                        case ' ':
                            vant = 0;
                            board[i+c][j+d] = 'B';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'B';
                            board[i+c][j+d] = ' ';
                            if(vant - AdvantageOponent > diferenceInAdvantage)
                            {
                                diferenceInAdvantage = vant - AdvantageOponent;
                                whiteAdvantage = vant;
                                blackAdvantage = AdvantageOponent;
                            }
                            break;
                        default:
                            diferenceInAdvantage = diferenceInAdvantage;
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
                                        vant = 1;
                                        board[i+c*a][j+d*a] = 'B';
                                        board[i][j] = ' ';
                                        engine1(board);
                                        board[i][j] = 'B';
                                        board[i+c*a][j+d*a] = 'p';
                                        if(vant - AdvantageOponent > diferenceInAdvantage)
                                        {
                                            diferenceInAdvantage = vant - AdvantageOponent;
                                            whiteAdvantage = vant;
                                            blackAdvantage = AdvantageOponent;
                                        }
                                        break;
                                    case 'c':
                                        vant = 3;
                                        board[i+c*a][j+d*a] = 'B';
                                        board[i][j] = ' ';
                                        engine1(board);
                                        board[i][j] = 'B';
                                        board[i+c*a][j+d*a] = 'c';
                                        if(vant - AdvantageOponent > diferenceInAdvantage)
                                        {
                                            diferenceInAdvantage = vant - AdvantageOponent;
                                            whiteAdvantage = vant;
                                            blackAdvantage = AdvantageOponent;
                                        }
                                        break;
                                    case 'b':
                                        vant = 3;
                                        board[i+c*a][j+d*a] = 'B';
                                        board[i][j] = ' ';
                                        engine1(board);
                                        board[i][j] = 'B';
                                        board[i+c*a][j+d*a] = 'b';
                                        if(vant - AdvantageOponent > diferenceInAdvantage)
                                        {
                                            diferenceInAdvantage = vant - AdvantageOponent;
                                            whiteAdvantage = vant;
                                            blackAdvantage = AdvantageOponent;
                                        }
                                        break;
                                    case 't':
                                        vant = 5;
                                        board[i+c*a][j+d*a] = 'B';
                                        board[i][j] = ' ';
                                        engine1(board);
                                        board[i][j] = 'B';
                                        board[i+c*a][j+d*a] = 't';
                                        if(vant - AdvantageOponent > diferenceInAdvantage)
                                        {
                                            diferenceInAdvantage = vant - AdvantageOponent;
                                            whiteAdvantage = vant;
                                            blackAdvantage = AdvantageOponent;
                                        }
                                        break;
                                    case 'd':
                                        vant = 9;
                                        board[i+c*a][j+d*a] = 'B';
                                        board[i][j] = ' ';
                                        engine1(board);
                                        board[i][j] = 'B';
                                        board[i+c*a][j+d*a] = 'd';
                                        if(vant - AdvantageOponent > diferenceInAdvantage)
                                        {
                                            diferenceInAdvantage = vant - AdvantageOponent;
                                            whiteAdvantage = vant;
                                            blackAdvantage = AdvantageOponent;
                                        }
                                        break;
                                    case ' ':
                                        vant = 0;
                                        board[i+c*a][j+d*a] = 'B';
                                        board[i][j] = ' ';
                                        engine1(board);
                                        board[i][j] = 'B';
                                        board[i+c*a][j+d*a] = ' ';
                                        if(vant - AdvantageOponent > diferenceInAdvantage)
                                        {
                                            diferenceInAdvantage = vant - AdvantageOponent;
                                            whiteAdvantage = vant;
                                            blackAdvantage = AdvantageOponent;
                                        }
                                        break;
                                    default:
                                        diferenceInAdvantage = diferenceInAdvantage;
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

void engineWhiteRook(char board[8][8], int i, int j)
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
                        vant = 1;
                        board[i+z][j] = 'T';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'T';
                        board[i+z][j] = 'p';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            whiteAdvantage = vant;
                            blackAdvantage = AdvantageOponent;
                        }
                        break;
                    case 'c':
                        vant = 3;
                        board[i+z][j] = 'T';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'T';
                        board[i+z][j] = 'c';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            whiteAdvantage = vant;
                            blackAdvantage = AdvantageOponent;
                        }
                        break;
                    case 'b':
                        vant = 3;
                        board[i+z][j] = 'T';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'T';
                        board[i+z][j] = 'b';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            whiteAdvantage = vant;
                            blackAdvantage = AdvantageOponent;
                        }
                        break;
                    case 't':
                        vant = 5;
                        board[i+z][j] = 'T';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'T';
                        board[i+z][j] = 't';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            whiteAdvantage = vant;
                            blackAdvantage = AdvantageOponent;
                        }
                        break;
                    case 'd':
                        vant = 9;
                        board[i+z][j] = 'T';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'T';
                        board[i+z][j] = 'd';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            whiteAdvantage = vant;
                            blackAdvantage = AdvantageOponent;
                        }
                        break;
                    case ' ':
                        vant = 0;
                        board[i+z][j] = 'T';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'T';
                        board[i+z][j] = ' ';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            whiteAdvantage = vant;
                            blackAdvantage = AdvantageOponent;
                        }
                        break;
                    default:
                        diferenceInAdvantage = diferenceInAdvantage;
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
                                vant = 1;
                                board[i+z*a][j] = 'T';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'T';
                                board[i+z*a][j] = 'p';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    whiteAdvantage = vant;
                                    blackAdvantage = AdvantageOponent;
                                }
                                break;
                            case 'c':
                                vant = 3;
                                board[i+z*a][j] = 'T';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'T';
                                board[i+z*a][j] = 'c';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    whiteAdvantage = vant;
                                    blackAdvantage = AdvantageOponent;
                                }
                                break;
                            case 'b':
                                vant = 3;
                                board[i+z*a][j] = 'T';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'T';
                                board[i+z*a][j] = 'b';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    whiteAdvantage = vant;
                                    blackAdvantage = AdvantageOponent;
                                }
                                break;
                            case 't':
                                vant = 5;
                                board[i+z*a][j] = 'T';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'T';
                                board[i+z*a][j] = 't';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    whiteAdvantage = vant;
                                    blackAdvantage = AdvantageOponent;
                                }
                                break;
                            case 'd':
                                vant = 9;
                                board[i+z*a][j] = 'T';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'T';
                                board[i+z*a][j] = 'd';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    whiteAdvantage = vant;
                                    blackAdvantage = AdvantageOponent;
                                }
                                break;
                            case ' ':
                                vant = 0;
                                board[i+z*a][j] = 'T';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'T';
                                board[i+z*a][j] = ' ';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    whiteAdvantage = vant;
                                    blackAdvantage = AdvantageOponent;
                                }
                                break;
                            default:
                                diferenceInAdvantage = diferenceInAdvantage;
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
                        vant = 1;
                        board[i][j+z] = 'T';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'T';
                        board[i][j+z] = 'p';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            whiteAdvantage = vant;
                            blackAdvantage = AdvantageOponent;
                        }
                        break;
                    case 'c':
                        vant = 3;
                        board[i][j+z] = 'T';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'T';
                        board[i][j+z] = 'c';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            whiteAdvantage = vant;
                            blackAdvantage = AdvantageOponent;
                        }
                        break;
                    case 'b':
                        vant = 3;
                        board[i][j+z] = 'T';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'T';
                        board[i][j+z] = 'b';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            whiteAdvantage = vant;
                            blackAdvantage = AdvantageOponent;
                        }
                        break;
                    case 't':
                        vant = 5;
                        board[i][j+z] = 'T';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'T';
                        board[i][j+z] = 't';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            whiteAdvantage = vant;
                            blackAdvantage = AdvantageOponent;
                        }
                        break;
                    case 'd':
                        vant = 9;
                        board[i][j+z] = 'T';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'T';
                        board[i][j+z] = 'd';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            whiteAdvantage = vant;
                            blackAdvantage = AdvantageOponent;
                        }
                        break;
                    case ' ':
                        vant = 0;
                        board[i][j+z] = 'T';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'T';
                        board[i][j+z] = ' ';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            whiteAdvantage = vant;
                            blackAdvantage = AdvantageOponent;
                        }
                        break;
                    default:
                        diferenceInAdvantage = diferenceInAdvantage;
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
                                vant = 1;
                                board[i][j+z*a] = 'T';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'T';
                                board[i][j+z*a] = 'p';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    whiteAdvantage = vant;
                                    blackAdvantage = AdvantageOponent;
                                }
                                break;
                            case 'c':
                                vant = 3;
                                board[i][j+z*a] = 'T';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'T';
                                board[i][j+z*a] = 'c';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    whiteAdvantage = vant;
                                    blackAdvantage = AdvantageOponent;
                                }
                                break;
                            case 'b':
                                vant = 3;
                                board[i][j+z*a] = 't';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'T';
                                board[i][j+z*a] = 'b';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    whiteAdvantage = vant;
                                    blackAdvantage = AdvantageOponent;
                                }
                                break;
                            case 't':
                                vant = 5;
                                board[i][j+z*a] = 'T';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'T';
                                board[i][j+z*a] = 't';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    whiteAdvantage = vant;
                                    blackAdvantage = AdvantageOponent;
                                }
                                break;
                            case 'd':
                                vant = 9;
                                board[i][j+z*a] = 'T';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'T';
                                board[i][j+z*a] = 'd';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    whiteAdvantage = vant;
                                    blackAdvantage = AdvantageOponent;
                                }
                                break;
                            case ' ':
                                vant = 0;
                                board[i][j+z*a] = 'T';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'T';
                                board[i][j+z*a] = ' ';
                                if(vant - AdvantageOponent > diferenceInAdvantage)
                                {
                                    diferenceInAdvantage = vant - AdvantageOponent;
                                    whiteAdvantage = vant;
                                    blackAdvantage = AdvantageOponent;
                                }
                                break;
                            default:
                                diferenceInAdvantage = diferenceInAdvantage;
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

void engineWhitePawn(char board[8][8], int i, int j)
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
                        vant = 1;
                        board[i-1][j+1*a] = 'P';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'P';
                        board[i-1][j+1*a] = 'p';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            whiteAdvantage = vant;
                            blackAdvantage = AdvantageOponent;
                        }
                        break;
                    case 'c':
                        vant = 3;
                        board[i-1][j+1*a] = 'P';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'P';
                        board[i-1][j+1*a] = 'c';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            whiteAdvantage = vant;
                            blackAdvantage = AdvantageOponent;
                        }
                        break;
                    case 'b':
                        vant = 3;
                        board[i-1][j+1*a] = 'P';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'P';
                        board[i-1][j+1*a] = 'b';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            whiteAdvantage = vant;
                            blackAdvantage = AdvantageOponent;
                        }
                        break;
                    case 't':
                        vant = 5;
                        board[i-1][j+1*a] = 'P';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'P';
                        board[i-1][j+1*a] = 't';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            whiteAdvantage = vant;
                            blackAdvantage = AdvantageOponent;
                        }
                        break;
                    case 'd':
                        vant = 9;
                        board[i-1][j+1*a] = 'P';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'P';
                        board[i-1][j+1*a] = 'd';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            whiteAdvantage = vant;
                            blackAdvantage = AdvantageOponent;
                        }
                        break;
                    case ' ':
                        vant = 0;
                        board[i-1][j+1*a] = 'P';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'P';
                        board[i-1][j+1*a] = ' ';
                        if(vant - AdvantageOponent > diferenceInAdvantage)
                        {
                            diferenceInAdvantage = vant - AdvantageOponent;
                            whiteAdvantage = vant;
                            blackAdvantage = AdvantageOponent;
                        }
                        break;
                    default:
                        diferenceInAdvantage = diferenceInAdvantage;
                        break; 
                }
            }
        }
    }
}