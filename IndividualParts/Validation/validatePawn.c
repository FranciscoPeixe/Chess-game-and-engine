int validatePawn(char fromColumn, int fromLine, int toLine, char toColumn, char board[8][8])
{
    if(toupper(board[8 - fromLine][fromColumn - 1]) == 'P')
    {
        if(toupper(board[8 - fromLine][fromColumn - 1]) == board[8 - fromLine][fromColumn - 1])
        {
            if(toLine > fromLine)
            {
                if(fromColumn == toColumn)
                {
                    if(fromLine == 2)
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
                    if(fromLine == 7 && toLine == 5)
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
