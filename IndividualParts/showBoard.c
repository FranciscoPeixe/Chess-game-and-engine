void showBoard(char fromColumn, int fromLine, int toLine, char toColumn, char board[8][8], char prom)
{
    switch(fromColumn)
    {
        case 'a':
            fromColumn = 1;
            break;
        case 'b':
            fromColumn = 2;
            break;
        case 'c':
            fromColumn = 3;
            break;
        case 'd':
            fromColumn = 4;
            break;
        case 'e':
            fromColumn = 5;
            break;
        case 'f':
            fromColumn = 6;
            break;
        case 'g':
            fromColumn = 7;
            break;
        case 'h':
            fromColumn = 8;
            break;
        default:
            fromColumn = 9;
            break;
    }
    switch(toColumn)
    {
        case 'a':
            toColumn = 1;
            break;
        case 'b':
            toColumn = 2;
            break;
        case 'c':
            toColumn = 3;
            break;
        case 'd':
            toColumn = 4;
            break;
        case 'e':
            toColumn = 5;
            break;
        case 'f':
            toColumn = 6;
            break;
        case 'g':
            toColumn = 7;
            break;
        case 'h':
            toColumn = 8;
            break;
        default:
            toColumn = 9;
            break;
    }
    illegalMove = 0;
    char temp = board[9 - toLine - 1][toColumn - 1];
    board[9 - toLine-1][toColumn-1] = board[9 - fromLine-1][fromColumn-1];
    board[9 - fromLine-1][fromColumn-1] = ' ';
    legal(board);
    board[9 - fromLine - 1][fromColumn - 1] = board[9 - toLine-1][toColumn-1];
    board[9 - toLine-1][toColumn-1] = temp;
    if(validatesquares(fromColumn, fromLine, toLine, toColumn, board) == 1)
    {
        printf(ORANGE"     ->You cannot move to the same square you started on.\n"RESET);
    }
    else if(fromColumn == 9 || toColumn == 9 || fromLine < 1 || fromLine > 8 || toLine < 1 || toLine > 8)
    {
        printf(ORANGE"      ->The coordinates you entered are not valid.\n"RESET);
    }
    else if(validatePlayer(board, fromLine, fromColumn) == 1)
    {
        printf(ORANGE"     ->It's not your turn.\n"RESET);
    }
    else if(validateCanibalism(fromColumn, fromLine, toLine, toColumn, board) == 1)
    {
        printf(ORANGE"     ->You cannot take your own pieces.\n"RESET);
    }
    else if(validateRook(fromColumn, fromLine, toLine, toColumn, board) == 1)
    {
        printf(ORANGE"     ->The rook cannot jump over pieces.\n"RESET);
    }
    else if(validateRook(fromColumn, fromLine, toLine, toColumn, board) == 2)
    {
        printf(ORANGE"     ->The rook moves horizontally or vertically.\n"RESET);
    }
    else if(validateKnight(fromColumn, fromLine, toLine, toColumn, board) == 1)
    {
        printf(ORANGE"     ->Invalid knight move.\n"RESET);
    }
    else if(validateKing(fromColumn, fromLine, toLine, toColumn, board) == 1)
    {
        printf(ORANGE"     ->The king can only move to any adjacent square.\n"RESET);
    }
    else if(validateBishop(fromColumn, fromLine, toLine, toColumn, board) == 1)
    {
        printf(ORANGE"     ->The bishop can only move along diagonal lines.\n"RESET);
    }
    else if(validateBishop(fromColumn, fromLine, toLine, toColumn, board) == 2)
    {
        printf(ORANGE"     ->The bishop cannot jump over pieces.\n"RESET);
    }
    else if((validateQuennCross(fromColumn, fromLine, toLine, toColumn, board) == 1 && validateQueenDiagonals(fromColumn, fromLine, toLine, toColumn, board) == 2) || (validateQuennCross(fromColumn, fromLine, toLine, toColumn, board) == 1 && validateQueenDiagonals(fromColumn, fromLine, toLine, toColumn, board) == 1))
    {
        printf(ORANGE"     ->The queen cannot jump over pieces.\n"RESET);
    }
    else if((validateQueenDiagonals(fromColumn, fromLine, toLine, toColumn, board) == 1 && validateQuennCross(fromColumn, fromLine, toLine, toColumn, board) == 2) || (validateQueenDiagonals(fromColumn, fromLine, toLine, toColumn, board) == 1 && validateQuennCross(fromColumn, fromLine, toLine, toColumn, board) == 1))
    {
        printf(ORANGE"     ->The queen can only move horizontally, vertically, or diagonally.\n"RESET);
    }
    else if((validateQuennCross(fromColumn, fromLine, toLine, toColumn, board) == 2 && validateQueenDiagonals(fromColumn, fromLine, toLine, toColumn, board) == 1) || (validateQuennCross(fromColumn, fromLine, toLine, toColumn, board) == 2 && validateQueenDiagonals(fromColumn, fromLine, toLine, toColumn, board) == 2))
    {
        printf(ORANGE"     ->The queen can only move horizontally, vertically, or diagonally.\n"RESET);
    }
    else if((validateQueenDiagonals(fromColumn, fromLine, toLine, toColumn, board) == 2 && validateQuennCross(fromColumn, fromLine, toLine, toColumn, board) == 1) || (validateQueenDiagonals(fromColumn, fromLine, toLine, toColumn, board) == 2 && validateQuennCross(fromColumn, fromLine, toLine, toColumn, board) == 2))
    {
        printf(ORANGE"     ->The queen can only move horizontally, vertically, or diagonally.\n"RESET);
    }
    else if(validatePawn(fromColumn, fromLine, toLine, toColumn, board) == 1)
    {
        printf(ORANGE"     ->Invalid pawn movement\n"RESET);
    }
    else if(validatePawn(fromColumn, fromLine, toLine, toColumn, board) == 2)
    {
        printf(ORANGE"     ->A pawn cannot jump over other pieces.\n"RESET);
    }
    else if(validateEndOfGame(toLine, toColumn, board) == 2)
    {
        printf("\n\n\n\n\n\n\n-------------------------------------------+         White wins          +------------------------------------------\n\n\n\n\n\n\n\n\n");
        exit(10);
    }
    else if(validateEndOfGame(toLine, toColumn, board) == 1)
    {
        printf("\n\n\n\n\n\n\n-------------------------------------------+         Black wins          +------------------------------------------\n\n\n\n\n\n\n\n\n");
        exit(10);
    }
    else if(illegalMove == 1)
    {
        printf(ORANGE"     ->Illegal move\n"RESET);
    }
    else
    {
        if(validateKing(fromColumn, fromLine, toLine, toColumn, board) == 2)
        {
            board[7][7] = ' ';
            board[7][5] = 'T';
        }
        else if(validateKing(fromColumn, fromLine, toLine, toColumn, board) == 3)
        {
            board[7][0] = ' ';
            board[7][3] = 'T';
        }
        else if(validateKing(fromColumn, fromLine, toLine, toColumn, board) == 4)
        {
            board[0][7] = ' ';
            board[0][5] = 't';
        }
        else if(validateKing(fromColumn, fromLine, toLine, toColumn, board) == 5)
        {
            board[0][0] = ' ';
            board[0][3] = 't';
        }
        else if(validatePawn(fromColumn, fromLine, toLine, toColumn, board) == 3)
        {
            if(moves % 2 == 0)//sao as brancas
            {
                printf("Quer promover para (D, T, B, C):");
                getchar();
                scanf("%c", &prom);
                prom = toupper(prom);
                board[8 - fromLine][fromColumn - 1] = prom;
            }
            else//sao as negras
            {
                printf("Quer promover para (d, t, b, c):");
                getchar();
                scanf("%c", &prom);
                board[8 - fromLine][fromColumn - 1] = ' ';
                board[8 - toLine][toColumn - 1] = prom;
            }
        }
        addCapturesPoints(toLine, toColumn, board);        
        defineCapturedPieces(toLine, toColumn, board);
        if(validatePawn(fromColumn, fromLine, toLine, toColumn, board) != 3)
        {
            board[9 - toLine-1][toColumn-1] = board[9 - fromLine-1][fromColumn-1];
            board[9 - fromLine-1][fromColumn-1] = ' ';
        }        
        //comecar a imprimir o tabuleiro
        system("cls");
        printf("\n\n");
        printf("White captured: ");
        for(int i = 0; i < numberOfPiecesCapturedWhite; i++)
        {
            if(i>0)
            {
                printf(", ");
            }
            printf("%c", piecesCapturedWhite[i]);
        }
        printf("    (%d points)", pointsCapturedWhite);
        printf("\n\n");
        printf("Black captured: ");
        for(int i = 0; i < numberOfPiecesCapturedBlack; i++)
        {
            if(i>0)
            {
                printf(", ");
            }
            printf("%c", piecesCapturedBlack[i]);
        }
        printf("    (%d points)", pointsCapturedBlack);
        printf("\n\n");
        if(moves % 2 == 1)
        {
            printf("-------------------------------------------------------------   White's turn    ----------------------------------------------------------\n\n\n");
        }
        else
        {
            printf("-------------------------------------------------------------   Black's turn    ----------------------------------------------------------\n\n\n");
        }
        engine(board);
	    if(moves % 2 == 1)
        {
            printf("        ");
            for(int i = 0; i < 8; i++)//mostra a linha de cima
            {
                printf("+---");
            }
            printf("+");
            printf("\n");
            for(int i = 0; i < 16; i++)//linhas
            {
                showEvaluationBar(i);
                printf("%d. |", 8 - i/2);
                for(int j = 0; j < 8; j++)//colunas
                {
                    if(board[i/2][j] == toupper(board[i/2][j]))
                    {
                    printf(RED" %c "RESET, board[i/2][j]);
                    }
                    else
                    {
                        printf(GREEN" %c "RESET, toupper(board[i/2][j]));
                    }
                    printf("|");
                }
                printf("\n");
                i++;
                showEvaluationBar(i);
                printf("   ");
                for(int j = 0; j < 8; j++)//escreve uma linha depois de cada conjunto de 8 squares
                {
                    printf("+---");
                }
                printf("+");
                printf("\n");
            }
            if(pointsCapturedWhite+whiteAdvantage > pointsCapturedBlack+blackAdvantage)
            {
                printf(" +%.1f", pointsCapturedWhite+whiteAdvantage-pointsCapturedBlack-blackAdvantage);
            }
            else if(pointsCapturedBlack+blackAdvantage > pointsCapturedWhite+whiteAdvantage)
            {
                printf(" -%.1f.1", pointsCapturedBlack+blackAdvantage-pointsCapturedWhite-whiteAdvantage);
            }
            else
            {
                printf(" +0.0");
            }
            printf("     A   B   C   D   E   F   G   H \n");
        }
        else
        {
            printf("        ");
            for(int i = 0; i < 8; i++)
            {
                printf("+---");
            }
            printf("+");
            printf("\n");
            for(int i = 0; i < 16; i++)
            {
                showEvaluationBar(15-i);
                printf("%d. |", i/2+1);
                for(int j = 0; j < 8; j++)
                {
                    if(board[7-i/2][7-j] == toupper(board[7-i/2][7-j]))
                    {
                    printf(RED" %c "RESET, board[7-i/2][7-j]);
                    }
                    else
                    {
                            printf(GREEN" %c "RESET, toupper(board[7-i/2][7-j]));
                    }
                    printf("|");
                }
                printf("\n");
                i++;
                showEvaluationBar(15-i);
                printf("   ");
                for(int j = 0; j < 8; j++)
                {
                    printf("+---");
                }
                printf("+\n");
            }
            if(pointsCapturedWhite+whiteAdvantage > pointsCapturedBlack+blackAdvantage)
            {
                printf(" +%.1f", pointsCapturedWhite+whiteAdvantage-pointsCapturedBlack-blackAdvantage);
            }
            else if(pointsCapturedBlack+blackAdvantage > pointsCapturedWhite+whiteAdvantage)
            {
                printf(" -%.1f", pointsCapturedBlack+blackAdvantage-pointsCapturedWhite-whiteAdvantage);
            }
            else
            {
                printf(" +0.0");
            }
            printf("     H   G   F   E   D   C   B   A\n");
        }
        moves++;
        printf("\n");
    }
}
