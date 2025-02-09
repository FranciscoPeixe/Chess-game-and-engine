#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define RESET "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define ORANGE "\x1B[33m"

void showBoard(char fromColumn, int fromLine, int toLine, char toColumn, char board[8][8], char prom);
int validateRook(char fromColumn, int fromLine, int toLine, char toColumn, char board[8][8]);
int validateKnight(char fromColumn, int fromLine, int toLine, char toColumn, char board[8][8]);
int validatesquares(char fromColumn, int fromLine, int toLine, char toColumn, char board[8][8]);
int validateBishop(char fromColumn, int fromLine, int toLine, char toColumn, char board[8][8]);
int validateCanibalism(char fromColumn, int fromLine, int toLine, char toColumn, char board[8][8]);
int validateKing(char fromColumn, int fromLine, int toLine, char toColumn, char board[8][8]);
int validateQuennCross(char fromColumn, int fromLine, int toLine, char toColumn, char board[8][8]);
int validateQueenDiagonals(char fromColumn, int fromLine, int toLine, char toColumn, char board[8][8]);
int validatePawn(char fromColumn, int fromLine, int toLine, char toColumn, char board[8][8]);
int validatePlayer(char board[8][8], int fromLine, int fromColumn);
int validateEndOfGame(int toLine, int toColumn, char board[8][8]);
void squares(char board[8][8]);
int addCapturesPoints(int toLine, int toColumn, char board[8][8]);
int defineCapturedPieces(int toLine, int toColumn, char board[8][8]);
void showEvaluationBar(int i);
void engine(char board[8][8]);
void engineBlackKing(char board[8][8], int i, int j);
void engineBlackKnight(char board[8][8], int i, int j);
void engineBlackBishop(char board[8][8], int i, int j);
void engineBlackRook(char board[8][8], int i, int j);
void engineBlackPawn(char board[8][8], int i, int j);
void engineBlackQueenCross(char board[8][8], int i, int j);
void engineBlackQueenDiagonals(char board[8][8], int i, int j);
void engineWhiteKing(char board[8][8], int i, int j);
void engineWhiteKnight(char board[8][8], int i, int j);
void engineWhiteBishop(char board[8][8], int i, int j);
void engineWhiteRook(char board[8][8], int i, int j);
void engineWhitePawn(char board[8][8], int i, int j);
void engineWhiteQueenCross(char board[8][8], int i, int j);
void engineWhiteQueenDiagonals(char board[8][8], int i, int j);
void engine1(char board[8][8]);
void engine1BlackKing(char board[8][8], int i, int j);
void engine1BlackKnight(char board[8][8], int i, int j);
void engine1BlackBishop(char board[8][8], int i, int j);
void engine1BlackRook(char board[8][8], int i, int j);
void engine1BlackPawn(char board[8][8], int i, int j);
void engine1WhiteKing(char board[8][8], int i, int j);
void engine1WhiteKnight(char board[8][8], int i, int j);
void engine1WhiteBishop(char board[8][8], int i, int j);
void engine1WhiteRook(char board[8][8], int i, int j);
void engine1WhitePawn(char board[8][8], int i, int j);
void legal(char board[8][8]);
void legalBlackKing(char board[8][8], int i, int j);
void legalBlackKnight(char board[8][8], int i, int j);
void legalBlackBishop(char board[8][8], int i, int j);
void legalBlackRook(char board[8][8], int i, int j);
void legalBlackPawn(char board[8][8], int i, int j);
void legalWhiteKing(char board[8][8], int i, int j);
void legalWhiteKnight(char board[8][8], int i, int j);
void legalWhiteBishop(char board[8][8], int i, int j);
void legalWhiteRook(char board[8][8], int i, int j);
void legalWhitePawn(char board[8][8], int i, int j);
int moves = 0;
int pointsCapturedWhite = 0;
int pointsCapturedBlack = 0;
char piecesCapturedWhite[16];
int numberOfPiecesCapturedWhite = 0;
char piecesCapturedBlack[16];
int numberOfPiecesCapturedBlack = 0;
float blackAdvantage = 0;
float whiteAdvantage = 0;
int AdvantageOponent = 0;
int diferenceInAdvantage = -100;
int vant = 0;
int illegalMove = 0;

int main()
{
    char board[8][8];
    char fromColumn;
    int fromLine;
    int toLine;
    char toColumn;
    char prom = ' ';
    system("cls");
    squares(board);
	while(1)
	{        
		printf("From square: ");
		scanf("%c%d", &fromColumn, &fromLine);
		printf("To square: ");
		getchar();
		scanf("%c%d", &toColumn, &toLine);
		getchar();
		showBoard(fromColumn, fromLine, toLine, toColumn, board, prom);
	}

    return 0;
}

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

int validateRook(char fromColumn, int fromLine, int toLine, char toColumn, char board[8][8])
{
    if(toupper(board[8 - fromLine][fromColumn - 1]) == 'T')
    {
        if(fromColumn == toColumn || fromLine == toLine)
        {
            int fromLineMatriz = 8 - fromLine;
            if(fromLine == toLine)//horizontal
            {
                if(toColumn > fromColumn)//para a direita
                {
                    for(int i = 0; i < toColumn - fromColumn - 1; i++)
                    {
                        if(board[fromLineMatriz][fromColumn + i] != ' ')
                        {
                            return 1;
                            break;
                        }
                    }
                }
                else//vai para a esquerda
                {
                    for(int i = 0; i < fromColumn - toColumn - 1; i++)
                    {
                        if(board[fromLineMatriz][fromColumn - i - 2] != ' ')
                        {
                            return 1;
                            break;
                        }
                    }
                    
                }
            }
            else//vertical
            {
                if(toLine > fromLine)//para a cima
                {
                    for(int i = 0; i <  toLine - fromLine - 1; i++)
                    {
                        if(board[fromLineMatriz - i - 1][fromColumn - 1] != ' ')
                        {
                            return 1;
                            break;
                        }
                    }
                }
                else//vai para a baiio
                {
                    for(int i = 0; i < fromLine - toLine - 1; i++)
                    {
                        if(board[fromLineMatriz + i + 1][fromColumn - 1] != ' ')
                        {
                            return 1;
                            break;
                        }
                    }
                    
                }
            }
        }
        else
        {
            return 2;
        }
    }
    else
    {
        return 0;
    }
    return 0;
}

int validateKnight(char fromColumn, int fromLine, int toLine, char toColumn, char board[8][8])
{
    if(board[8 - fromLine][fromColumn - 1] == 'C' || board[8 - fromLine][fromColumn - 1] == 'c')
    {
        if(toLine == fromLine + 2 && toColumn == fromColumn + 1)//cima direita
        {
            return 0;
        }
        else if(toLine == fromLine + 2 && toColumn == fromColumn - 1)//cima esquerda
        {
            return 0;
        }
        else if(toLine == fromLine + 1 && toColumn == fromColumn + 2)//cima lado direita
        {
            return 0;
        }
        else if(toLine == fromLine + 1 && toColumn == fromColumn - 2)//cima lado esquerda
        {
            return 0;
        }
        else if(toLine == fromLine - 1 && toColumn == fromColumn + 2)//baiio lado direita
        {
            return 0;
        }
        else if(toLine == fromLine - 1 && toColumn == fromColumn - 2)//baiio lado esquerda
        {
            return 0;
        }
        else if(toLine == fromLine - 2 && toColumn == fromColumn + 1)//baiio direita
        {
            return 0;
        }
        else if(toLine == fromLine - 2 && toColumn == fromColumn - 1)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

int validatesquares(char fromColumn, int fromLine, int toLine, char toColumn, char board[8][8])
{
    if(fromLine == toLine && fromColumn == toColumn)
    {
        return 1;
    }
    else if(board[8-fromLine][fromColumn-1] == ' ')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int validateCanibalism(char fromColumn, int fromLine, int toLine, char toColumn, char board[8][8])
{
    if(board[8 - toLine][toColumn - 1] != ' ')
    {
        if(board[8 - fromLine][fromColumn - 1] != ' ')
        {
            if(toupper(board[8 - fromLine][fromColumn - 1]) == board[8 - fromLine][fromColumn - 1])//peca branca
            {
                if(toupper(board[8 - toLine][toColumn - 1]) == board[8 - toLine][toColumn - 1])//a board de destino tambem e uma board com peca branca
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else//peca preta
            {
                if(toupper(board[8 - toLine][toColumn - 1]) != board[8 - toLine][toColumn - 1])//a board de destino tambem e uma board com peca preta
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

int validateKing(char fromColumn, int fromLine, int toLine, char toColumn, char board[8][8])
{
    if(toupper(board[8 - fromLine][fromColumn - 1]) == 'R')
    {
        if(fromLine == toLine && toColumn == fromColumn + 2 && fromLine == 1 && fromColumn == 5)//roque no lado do rei
        {
            if(board[7][5] == ' ' && board[7][6] == ' ' && board[7][7] == 'T')
            {
                return 2;
            }
        }
        else if(fromLine == toLine && toColumn == fromColumn - 2 && fromLine == 1 && fromColumn == 5)//roque no lado da dama
        {
            if(board[7][1] == ' ' && board[7][2] == ' ' &&  board[7][3] == ' ' && board[7][0] == 'T')
            {
                return 3;
            }
        }
        else if(fromLine == toLine && toColumn == fromColumn + 2 && fromLine == 8 && fromColumn == 5)//roque no lado do rei
        {
            if(board[0][5] == ' ' && board[0][6] == ' ' && board[0][7] == 't')
            {
                return 4;
            }
        }
        else if(fromLine == toLine && toColumn == fromColumn - 2 && fromLine == 8 && fromColumn == 5)//roque no lado da dama
        {
            if(board[0][1] == ' ' && board[0][2] == ' ' &&  board[0][3] == ' ' && board[0][0] == 't')
            {
                return 5;
            }
        }
        else if(fromLine + 1 == toLine && fromColumn == toColumn)//cim
        {
            return 0;
        }
        else if(fromLine - 1 == toLine && fromColumn == toColumn)//cim
        {
            return 0;
        }
        else if(fromLine == toLine && fromColumn + 1== toColumn)//cim
        {
            return 0;
        }
        else if(fromLine == toLine && fromColumn - 1 == toColumn)//cim
        {
            return 0;
        }
        else if(fromLine + 1 == toLine && fromColumn + 1 == toColumn)//cim
        {
            return 0;
        }
        else if(fromLine + 1 == toLine && fromColumn - 1 == toColumn)//cim
        {
            return 0;
        }
        else if(fromLine - 1 == toLine && fromColumn + 1 == toColumn)//cim
        {
            return 0;
        }
        else if(fromLine - 1 == toLine && fromColumn - 1 == toColumn)//cim
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
    return 0;
}

int validateBishop(char fromColumn, int fromLine, int toLine, char toColumn, char board[8][8])
{
    if(toupper(board[8 - fromLine][fromColumn - 1]) == 'B')
    {
        if(abs(toColumn - fromColumn) == abs(toLine - fromLine))
        {
            int fromLineMatriz = 8 - fromLine;
            int toLineMatriz = 8 - toLine;
            if(toLineMatriz < fromLineMatriz)//vai para cima
            {
                if(toColumn > fromColumn)//para a direita
                {
                    for(int i = 0; i < toLine - fromLine - 1; i++)
                    {
                        if(board[fromLineMatriz - i - 1][fromColumn + i] != ' ')
                        {
                            return 2;
                            break;
                        }
                    }
                }
                else//vai para a esquerda
                {
                    for(int i = 0; i < toLine - fromLine - 1; i++)
                    {
                        if(board[fromLineMatriz - i - 1][fromColumn - i - 2] != ' ')
                        {
                            return 2;
                            break;
                        }
                    }
                    
                }
            }
            else//vai para baiio
            {
                if(toColumn > fromColumn)//para a direita
                {
                    for(int i = 0; i < fromLine - toLine - 1; i++)
                    {
                        if(board[fromLineMatriz + i + 1][fromColumn + i] != ' ')
                        {
                            return 2;
                            break;
                        }
                    }
                }
                else//vai para a esquerda
                {
                    for(int i = 0; i < fromLine - toLine - 1; i++)
                    {
                        if(board[fromLineMatriz + i + 1][fromColumn - i - 2] != ' ')
                        {
                            return 2;
                            break;
                        }
                    }
                    
                }
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
    return 0;
}

int validateQuennCross(char fromColumn, int fromLine, int toLine, char toColumn, char board[8][8])
{
    if(toupper(board[8 - fromLine][fromColumn - 1]) == 'D')
    {
        if(fromColumn == toColumn || fromLine == toLine)
        {
            int fromLineMatriz = 8 - fromLine;
            if(fromLine == toLine)//horizontal
            {
                if(toColumn > fromColumn)//para a direita
                {
                    for(int i = 0; i < toColumn - fromColumn - 1; i++)
                    {
                        if(board[fromLineMatriz][fromColumn + i] != ' ')
                        {
                            return 1;
                            break;
                        }
                    }
                }
                else//vai para a esquerda
                {
                    for(int i = 0; i < fromColumn - toColumn - 1; i++)
                    {
                        if(board[fromLineMatriz][fromColumn - i - 2] != ' ')
                        {
                            return 1;
                            break;
                        }
                    }
                    
                }
            }
            else//vertical
            {
                if(toLine > fromLine)//para a cima
                {
                    for(int i = 0; i <  toLine - fromLine - 1; i++)
                    {
                        if(board[fromLineMatriz - i - 1][fromColumn - 1] != ' ')
                        {
                            return 1;
                            break;
                        }
                    }
                }
                else//vai para a baiio
                {
                    for(int i = 0; i < fromLine - toLine - 1; i++)
                    {
                        if(board[fromLineMatriz + i + 1][fromColumn - 1] != ' ')
                        {
                            return 1;
                            break;
                        }
                    }
                    
                }
            }
        }
        else
        {
            return 2;
        }
    }
    else
    {
        return 0;
    }
    return 0;
}

int validateQueenDiagonals(char fromColumn, int fromLine, int toLine, char toColumn, char board[8][8])
{
    if(toupper(board[8 - fromLine][fromColumn - 1]) == 'D')
    {
        if(abs(toColumn - fromColumn) == abs(toLine - fromLine))
        {
            int fromLineMatriz = 8 - fromLine;
            int toLineMatriz = 8 - toLine;
            if(toLineMatriz < fromLineMatriz)//vai para cima
            {
                if(toColumn > fromColumn)//para a direita
                {
                    for(int i = 0; i < toLine - fromLine - 1; i++)
                    {
                        if(board[fromLineMatriz - i - 1][fromColumn + i] != ' ')
                        {
                            return 2;
                            break;
                        }
                    }
                }
                else//vai para a esquerda
                {
                    for(int i = 0; i < toLine - fromLine - 1; i++)
                    {
                        if(board[fromLineMatriz - i - 1][fromColumn - i - 2] != ' ')
                        {
                            return 2;
                            break;
                        }
                    }
                    
                }
            }
            else//vai para baiio
            {
                if(toColumn > fromColumn)//para a direita
                {
                    for(int i = 0; i < fromLine - toLine - 1; i++)
                    {
                        if(board[fromLineMatriz + i + 1][fromColumn + i] != ' ')
                        {
                            return 2;
                            break;
                        }
                    }
                }
                else//vai para a esquerda
                {
                    for(int i = 0; i < fromLine - toLine - 1; i++)
                    {
                        if(board[fromLineMatriz + i + 1][fromColumn - i - 2] != ' ')
                        {
                            return 2;
                            break;
                        }
                    }
                    
                }
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
    return 0;
}

int validatePawn(char fromColumn, int fromLine, int toLine, char toColumn, char board[8][8])
{
    if(toupper(board[8 - fromLine][fromColumn - 1]) == 'P')
    {
        if(toupper(board[8 - fromLine][fromColumn - 1]) == board[8 - fromLine][fromColumn - 1])//peao branco
        {
            if(toLine > fromLine)
            {
                if(fromColumn == toColumn)
                {
                    if(fromLine == 2)//esta na board inicial
                    {
                        if(toLine - fromLine < 3 && toLine == 4)
                        {
                            if(board[7 - fromLine][fromColumn - 1] == ' ' && board[6 - fromLine][fromColumn - 1] == ' ')
                            {
                                return 0;
                            }
                            else{
                                return 2;
                            }
                        }
                        else if(toLine - fromLine < 3 && toLine == 3)
                        {
                            if(board[7 - fromLine][fromColumn - 1] == ' ')
                            {
                                return 0;
                            }
                            else
                            {
                                return 1;
                            }
                        }
                        else
                        {
                            return 1;
                        }
                    }
                    else if(fromLine == 7 && toLine == 8 && board[8 - toLine][toColumn - 1] == ' ')
                    {
                        return 3;
                    }
                    else
                    {
                        if(toLine - fromLine == 1)
                        {
                            if(board[7 - fromLine][fromColumn - 1] == ' ')
                            {
                                return 0;
                            }
                            else
                            {
                                return 2;
                            }
                        }
                        else
                        {
                            return 1;
                        }
                    }
                }
                else if(toColumn == fromColumn + 1 && toLine == fromLine + 1 && board[8 - toLine][toColumn - 1] != ' ' && 7 == fromLine && toLine == 8)
                {
                    return 3;
                }
                else if(toColumn == fromColumn - 1 && toLine == fromLine + 1  && board[8 - toLine][toColumn - 1] != ' ' && 7 == fromLine && toLine == 8)
                {
                    return 3;
                }
                else if(toColumn == fromColumn + 1 && toLine == fromLine + 1 && board[8 - toLine][toColumn - 1] != ' ')
                {
                    return 0;
                }
                else if(toColumn == fromColumn - 1 && toLine == fromLine + 1  && board[8 - toLine][toColumn - 1] != ' ')
                {
                    return 0;
                }
                else
                {
                    return 1;
                }
            }
            else
            {
                return 1;
            }
        }
        else
        {
            if(toLine < fromLine)
            {
                if(fromColumn == toColumn)
                {
                    if(fromLine == 7 && toLine == 5)//esta na board inicial
                    {
                        if(board[9 - fromLine][fromColumn - 1] == ' ' && board[10 - fromLine][fromColumn - 1] == ' ')
                        {
                            return 0;
                        }
                        else{
                            return 2;
                        }
                    }
                    else if(fromLine == 2 && toLine == 1 && board[8 - toLine][toColumn - 1] == ' ')
                    {
                        return 3;
                    }
                    else
                    {
                        if(fromLine - toLine == 1)
                        {
                             if(board[9 - fromLine][fromColumn - 1] == ' ')
                            {
                                return 0;
                            }
                            else
                            {
                                return 2;
                            }
                        }
                        else
                        {
                            return 1;
                        }
                    }
                }
                else if(toColumn == fromColumn + 1 && toLine == fromLine - 1 && board[8 - toLine][toColumn - 1] != ' ' && 2 == fromLine && toLine == 1)
                {
                    return 3;
                }
                else if(toColumn == fromColumn - 1 && toLine == fromLine - 1 && board[8 - toLine][toColumn - 1] != ' ' && 2 == fromLine && toLine == 1)
                {
                    return 3;
                }
                else if(toColumn == fromColumn + 1 && toLine == fromLine - 1 && board[8 - toLine][toColumn - 1] != ' ')
                {
                    return 0;
                }
                else if(toColumn == fromColumn - 1 && toLine == fromLine - 1 && board[8 - toLine][toColumn - 1] != ' ')
                {
                    return 0;
                }
                else
                {
                    return 1;
                }
            }
            else
            {
                return 1;
            }
        }
    }
    return 0;
}

int validatePlayer(char board[8][8], int fromLine, int fromColumn)
{
    if((moves % 2 == 0 && board[8-fromLine][fromColumn-1] == toupper(board[8-fromLine][fromColumn-1])) || 
    (moves % 2 == 1 && board[8-fromLine][fromColumn-1] != toupper(board[8-fromLine][fromColumn-1])))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int addCapturesPoints(int toLine, int toColumn, char board[8][8])
{
    if(moves % 2 == 0)
    {
        switch(board[8-toLine][toColumn-1])
        {
            case 'p':
                pointsCapturedWhite++;
                break;
            case 'c':
                pointsCapturedWhite+=3;
                break;
            case 'b':
                pointsCapturedWhite+=3;
                break;
            case 't':
                pointsCapturedWhite+=5;
                break;
            case 'd':
                pointsCapturedWhite+=9;
                break;
        }
    }
    else if(moves % 2 == 1)
    {
        switch(board[8-toLine][toColumn-1])
        {
            case 'P':
                pointsCapturedBlack++;
                break;
            case 'C':
                pointsCapturedBlack+=3;
                break;
            case 'B':
                pointsCapturedBlack+=3;
                break;
            case 'T':
                pointsCapturedBlack+=5;
                break;
            case 'D':
                pointsCapturedBlack+=9;
                break;
        }
    }
    return 0;
}

int validateEndOfGame(int toLine, int toColumn, char board[8][8])
{  
    if(toupper(board[8-toLine][toColumn-1]) == 'R')
    {
        if(moves % 2 == 1)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        return 0;
    }
}

int defineCapturedPieces(int toLine, int toColumn, char board[8][8])
{
    if(board[8-toLine][toColumn-1] != ' ')
    {
        if(moves % 2 == 0)
        {
           piecesCapturedWhite[numberOfPiecesCapturedWhite] = board[8-toLine][toColumn-1]; 
           numberOfPiecesCapturedWhite++;
        }
        else
        {
           piecesCapturedBlack[numberOfPiecesCapturedBlack] = board[8-toLine][toColumn-1];
           numberOfPiecesCapturedBlack++;
        }
    }
    return 0;
}

void showEvaluationBar(int i)
{
    if((pointsCapturedWhite+whiteAdvantage == pointsCapturedBlack+blackAdvantage)
     || (whiteAdvantage < 1 && blackAdvantage < 1)
     || (abs(whiteAdvantage - blackAdvantage) < 1))
    {
        if(i < 8)
        {
            printf("|  | ");
        }
        else
        {
            printf("|||| ");
        }
    }
    else if(pointsCapturedWhite+whiteAdvantage > pointsCapturedBlack+blackAdvantage)
    {
        if(i < 6/(pointsCapturedWhite+whiteAdvantage-pointsCapturedBlack-blackAdvantage))
        {
            printf("|  | ");
        }
        else
        {
            printf("|||| ");
        }
    }
    else
    {
        if(i < 16 - 6/(pointsCapturedBlack+blackAdvantage-pointsCapturedWhite-whiteAdvantage))
        {
            printf("|  | ");
        }
        else
        {
            printf("|||| ");
        }
    }
}

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
                    engineBlackQueenCross(board, i, j);
                    engineBlackQueenDiagonals(board, i, j);
                }
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
                    engineWhiteQueenCross(board, i, j);
                    engineWhiteQueenDiagonals(board, i, j);
                }
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
    if(board[i][j] == 'b')
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

void engineBlackQueenDiagonals(char board[8][8], int i, int j)
{
    if(board[i][j] == 'd')
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
                            board[i+c][j+d] = 'd';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'd';
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
                            board[i+c][j+d] = 'd';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'd';
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
                            board[i+c][j+d] = 'd';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'd';
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
                            board[i+c][j+d] = 'd';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'd';
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
                            board[i+c][j+d] = 'd';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'd';
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
                            board[i+c][j+d] = 'd';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'd';
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
                                        board[i+c*a][j+d*a] = 'd';
                                        board[i][j] = ' ';
                                        engine1(board);
                                        board[i][j] = 'd';
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
                                        board[i+c*a][j+d*a] = 'd';
                                        board[i][j] = ' ';
                                        engine1(board);
                                        board[i][j] = 'd';
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
                                        board[i+c*a][j+d*a] = 'd';
                                        board[i][j] = ' ';
                                        engine1(board);
                                        board[i][j] = 'd';
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
                                        board[i+c*a][j+d*a] = 'd';
                                        board[i][j] = ' ';
                                        engine1(board);
                                        board[i][j] = 'd';
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
                                        board[i+c*a][j+d*a] = 'd';
                                        board[i][j] = ' ';
                                        engine1(board);
                                        board[i][j] = 'd';
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
                                        board[i+c*a][j+d*a] = 'd';
                                        board[i][j] = ' ';
                                        engine1(board);
                                        board[i][j] = 'd';
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
    if(board[i][j] == 't')
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

void engineBlackQueenCross(char board[8][8], int i, int j)
{
    if(board[i][j] == 'd')
    {
        for(int z = -1; z < 2; z+=2)
        {
            if(board[i+z][j] == toupper(board[i+z][j]) && board[i+z][j] != ' ')
            {
                switch(board[i+z][j])
                {
                    case 'P':
                        vant = 1;
                        board[i+z][j] = 'd';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'd';
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
                        board[i+z][j] = 'd';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'd';
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
                        board[i+z][j] = 'd';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'd';
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
                        board[i+z][j] = 'd';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'd';
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
                        board[i+z][j] = 'd';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'd';
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
                        board[i+z][j] = 'd';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'd';
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
                                board[i+z*a][j] = 'd';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'd';
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
                                board[i+z*a][j] = 'd';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'd';
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
                                board[i+z*a][j] = 'd';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'd';
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
                                board[i+z*a][j] = 'd';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'd';
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
                                board[i+z*a][j] = 'd';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'd';
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
                                board[i+z*a][j] = 'd';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'd';
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
                        board[i][j+z] = 'd';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'd';
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
                        board[i][j+z] = 'd';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'd';
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
                        board[i][j+z] = 'd';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'd';
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
                        board[i][j+z] = 'd';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'd';
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
                        board[i][j+z] = 'd';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'd';
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
                        board[i][j+z] = 'd';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'd';
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
                                board[i][j+z*a] = 'd';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'd';
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
                                board[i][j+z*a] = 'd';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'd';
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
                                board[i][j+z*a] = 'd';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'd';
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
                                board[i][j+z*a] = 'd';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'd';
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
                                board[i][j+z*a] = 'd';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'd';
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
                                board[i][j+z*a] = 'd';
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
    if(board[i][j] == 'B')
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

void engineWhiteQueenDiagonals(char board[8][8], int i, int j)
{
    if(board[i][j] == 'D')
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
                            board[i+c][j+d] = 'D';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'D';
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
                            board[i+c][j+d] = 'D';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'D';
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
                            board[i+c][j+d] = 'D';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'D';
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
                            board[i+c][j+d] = 'D';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'D';
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
                            board[i+c][j+d] = 'D';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'D';
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
                            board[i+c][j+d] = 'D';
                            board[i][j] = ' ';
                            engine1(board);
                            board[i][j] = 'D';
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
                                        board[i+c*a][j+d*a] = 'D';
                                        board[i][j] = ' ';
                                        engine1(board);
                                        board[i][j] = 'D';
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
                                        board[i+c*a][j+d*a] = 'D';
                                        board[i][j] = ' ';
                                        engine1(board);
                                        board[i][j] = 'D';
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
                                        board[i+c*a][j+d*a] = 'D';
                                        board[i][j] = ' ';
                                        engine1(board);
                                        board[i][j] = 'D';
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
                                        board[i+c*a][j+d*a] = 'D';
                                        board[i][j] = ' ';
                                        engine1(board);
                                        board[i][j] = 'D';
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
                                        board[i+c*a][j+d*a] = 'D';
                                        board[i][j] = ' ';
                                        engine1(board);
                                        board[i][j] = 'D';
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
                                        board[i+c*a][j+d*a] = 'D';
                                        board[i][j] = ' ';
                                        engine1(board);
                                        board[i][j] = 'D';
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
    if(board[i][j] == 'T')
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

void engineWhiteQueenCross(char board[8][8], int i, int j)
{
    if(board[i][j] == 'D')
    {
        for(int z = -1; z < 2; z+=2)
        {
            if(board[i+z][j] != toupper(board[i+z][j]) && board[i+z][j] != ' ')
            {
                switch(board[i+z][j])
                {
                    case 'p':
                        vant = 1;
                        board[i+z][j] = 'D';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'D';
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
                        board[i+z][j] = 'D';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'D';
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
                        board[i+z][j] = 'D';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'D';
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
                        board[i+z][j] = 'D';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'D';
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
                        board[i+z][j] = 'D';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'D';
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
                        board[i+z][j] = 'D';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'D';
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
                                board[i+z*a][j] = 'D';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'D';
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
                                board[i+z*a][j] = 'D';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'D';
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
                                board[i+z*a][j] = 'D';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'D';
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
                                board[i+z*a][j] = 'D';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'D';
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
                                board[i+z*a][j] = 'D';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'D';
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
                                board[i+z*a][j] = 'D';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'D';
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
                        board[i][j+z] = 'D';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'D';
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
                        board[i][j+z] = 'D';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'D';
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
                        board[i][j+z] = 'D';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'D';
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
                        board[i][j+z] = 'D';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'D';
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
                        board[i][j+z] = 'D';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'D';
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
                        board[i][j+z] = 'D';
                        board[i][j] = ' ';
                        engine1(board);
                        board[i][j] = 'D';
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
                                board[i][j+z*a] = 'D';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'D';
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
                                board[i][j+z*a] = 'D';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'D';
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
                                board[i][j+z*a] = 'D';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'D';
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
                                board[i][j+z*a] = 'D';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'D';
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
                                board[i][j+z*a] = 'D';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'D';
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
                                board[i][j+z*a] = 'D';
                                board[i][j] = ' ';
                                engine1(board);
                                board[i][j] = 'D';
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
