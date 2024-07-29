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
