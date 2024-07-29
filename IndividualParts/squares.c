void squares(char board[8][8]) //define as squares iniciais
{
    //definir as squares sem pecas como espaco para formatar
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            board[i][j] = ' ';
        }
    }
    //definir as posicões iniciais das pecas
    //pecas brancas
    for(int i = 0; i < 8; i++)//definir todas as squares da linha 2 (board[6]) como peões
    {
        board[6][i] = 'P';
    }
    board[7][1] = 'C';
    board[7][6] = 'C';
    board[7][0] = 'T';
    board[7][7] = 'T';
    board[7][2] = 'B';
    board[7][5] = 'B';
    board[7][3] = 'D';
    board[7][4] = 'R';
    // pecas negras
    for(int i = 0; i < 8; i++)//definir todas as squares da linha 7 (board[1]) como peões
    {
        board[1][i] = 'p';
    }
    board[0][1] = 'c';
    board[0][6] = 'c';
    board[0][0] = 't';
    board[0][7] = 't';
    board[0][2] = 'b';
    board[0][5] = 'b';
    board[0][3] = 'd';
    board[0][4] = 'r';
    printf("        ");
    for(int i = 0; i < 8; i++)//mostra a linha de cima
    {
        printf("+---"); 
    }
    printf("+");
    printf("\n");
    for(int i = 0; i < 8; i++)//linhas
    {
        (i < 4)?printf("|  | "):printf("|||| ");
        printf("%d. |", 8 - i);
        for(int j = 0; j < 8; j++)//colunas
        {
          if(board[i][j] == toupper(board[i][j]))
          {
          	printf(RED" %c "RESET, board[i][j]);
          }
          else
          {
                      printf(GREEN" %c "RESET, toupper(board[i][j]));
          }
          printf("|");
       }
        printf("\n");
        (i < 4)?printf("|  | "):printf("|||| ");
        printf("   ");
        for(int i = 0; i < 8; i++)
        {
            printf("+---");
        }
        printf("+");
        printf("\n");
    }
    if(pointsCapturedWhite == pointsCapturedBlack)
    {
        printf(" +0.1");
    }
    else if(pointsCapturedWhite > pointsCapturedBlack)
    {
        printf(" +%d", pointsCapturedWhite-pointsCapturedBlack);
    }
    else
    {
        printf(" -%d", pointsCapturedBlack-pointsCapturedWhite);
    }
    printf("     A   B   C   D   E   F   G   H  \n");//mostrar coordenadas
}
