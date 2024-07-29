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
