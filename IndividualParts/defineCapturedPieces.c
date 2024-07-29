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
