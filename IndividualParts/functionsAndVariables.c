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
void engineWhiteKing(char board[8][8], int i, int j);
void engineWhiteKnight(char board[8][8], int i, int j);
void engineWhiteBishop(char board[8][8], int i, int j);
void engineWhiteRook(char board[8][8], int i, int j);
void engineWhitePawn(char board[8][8], int i, int j);
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

const float vantPawn[8][8] = {
   /*8*/ {10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f},
   /*7*/ { 3.5f,  4.0f,  4.0f,  4.0f,  4.0f,  4.0f,  4.0f,  3.5f},
   /*6*/ { 0.6f,  0.9f,  0.9f,  0.9f,  0.9f,  0.9f,  0.9f,  0.6f},
   /*5*/ { 0.2f,  0.3f,  0.4f,  0.5f,  0.5f,  0.3f,  0.3f,  0.2f},
   /*4*/ { 0.0f,  0.1f,  0.1f,  0.2f,  0.2f,  0.1f,  0.1f,  0.0f},
   /*3*/ { 0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f},
   /*2*/ { 0.0f,  0.1f,  0.1f,  0.1f,  0.1f,  0.1f,  0.1f,  0.0f},
   /*1*/ { 0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f}
};

const float vantKnight[8][8] = {
   /*8*/ { 0.1f,  0.1f,  0.1f,  0.2f,  0.2f,  0.1f,  0.1f,  0.1f},
   /*7*/ { 0.5f,  0.5f,  0.5f,  0.6f,  0.6f,  0.5f,  0.5f,  0.5f},
   /*6*/ { 0.6f,  0.9f,  0.9f,  0.9f,  0.9f,  0.9f,  0.9f,  0.6f},
   /*5*/ { 0.3f,  0.4f,  0.5f,  0.7f,  0.7f,  0.5f,  0.4f,  0.3f},
   /*4*/ { 0.3f,  0.3f,  0.4f,  0.4f,  0.4f,  0.4f,  0.3f,  0.3f},
   /*3*/ { 0.2f,  0.2f,  0.2f,  0.3f,  0.3f,  0.2f,  0.2f,  0.2f},
   /*2*/ { 0.1f,  0.2f,  0.2f,  0.3f,  0.3f,  0.2f,  0.2f,  0.1f},
   /*1*/ { 0.0f,  0.1f,  0.1f,  0.1f,  0.1f,  0.1f,  0.1f,  0.0f}
};          /*a*/  /*b*/  /*c*/  /*d*/  /*e*/ /*f*/  /*g*/  /*h*/ 

const float vantBishop[8][8] = {
   /*8*/ {-0.4f, -0.4f, -0.4f, -0.4f, -0.4f, -0.4f, -0.4f, -0.4f},
   /*7*/ { 0.5f,  0.5f,  0.5f,  0.5f,  0.5f,  0.5f,  0.5f,  0.5f},
   /*6*/ { 0.5f,  0.5f,  0.5f,  0.5f,  0.5f,  0.5f,  0.5f,  0.5f},
   /*5*/ { 0.5f,  0.5f,  0.6f,  0.6f,  0.6f,  0.6f,  0.5f,  0.5f},
   /*4*/ { 0.5f,  0.5f,  0.8f,  0.6f,  0.6f,  0.8f,  0.5f,  0.5f},
   /*3*/ { 0.5f,  0.8f,  0.6f,  0.6f,  0.6f,  0.6f,  0.8f,  0.5f},
   /*2*/ { 0.6f,  0.8f,  0.8f,  0.7f,  0.7f,  0.8f,  0.8f,  0.6f},
   /*1*/ { 0.6f,  0.6f,  0.6f,  0.5f,  0.5f,  0.6f,  0.6f,  0.6f}
};          /*a*/  /*b*/  /*c*/  /*d*/  /*e*/ /*f*/  /*g*/  /*h*/ 

const float vantRook[8][8] = {
   /*8*/ { 1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f},
   /*7*/ { 1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f},
   /*6*/ { 1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f},
   /*5*/ { 1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f},
   /*4*/ { 1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.4f,  1.3f,  1.3f},
   /*3*/ { 1.1f,  1.1f,  1.0f,  1.0f,  1.0f,  1.0f,  1.1f,  1.1f},
   /*2*/ { 1.1f,  1.1f,  1.0f,  1.1f,  1.1f,  1.0f,  1.1f,  1.1f},
   /*1*/ { 1.1f,  1.1f,  1.0f,  1.2f,  1.2f,  1.0f,  1.1f,  1.1f}
};          /*a*/  /*b*/  /*c*/  /*d*/  /*e*/ /*f*/  /*g*/  /*h*/ 

const float vantQueen[8][8] = {
   /*8*/ { 2.3f,  2.3f,  2.3f,  2.3f,  2.3f,  2.3f,  2.3f,  2.3f},
   /*7*/ { 2.3f,  2.3f,  2.3f,  2.3f,  2.3f,  2.3f,  2.3f,  2.3f},
   /*6*/ { 2.3f,  2.3f,  2.3f,  2.3f,  2.3f,  2.3f,  2.3f,  2.3f},
   /*5*/ { 2.3f,  2.3f,  2.3f,  2.3f,  2.3f,  2.3f,  2.3f,  2.3f},
   /*4*/ { 2.3f,  2.3f,  2.3f,  2.3f,  2.3f,  2.3f,  2.3f,  2.3f},
   /*3*/ { 2.3f,  2.3f,  2.3f,  2.3f,  2.3f,  2.3f,  2.3f,  2.3f},
   /*2*/ { 2.3f,  2.3f,  2.3f,  2.3f,  2.3f,  2.3f,  2.3f,  2.3f},
   /*2*/ { 2.3f,  2.3f,  2.3f,  2.3f,  2.3f,  2.3f,  2.3f,  2.3f}
};          /*a*/  /*b*/  /*c*/  /*d*/  /*e*/ /*f*/  /*g*/  /*h*/ 

const float vantKing[8][8] = {
   /*8*/ { 0.1f,  0.1f,  0.1f,  0.1f,  0.1f,  0.1f,  0.1f,  0.1f},
   /*7*/ { 0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f},
   /*6*/ { 0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f},
   /*5*/ { 0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f},
   /*4*/ { 0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f},
   /*3*/ { 0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f},
   /*2*/ { 0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f},
   /*1*/ { 0.1f,  0.2f,  0.1f, -0.3f, -0.1f,  0.1f,  0.2f,  0.1f}
};          /*a*/  /*b*/  /*c*/  /*d*/  /*e*/ /*f*/  /*g*/  /*h*/ 
