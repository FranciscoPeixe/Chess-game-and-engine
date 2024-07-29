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
