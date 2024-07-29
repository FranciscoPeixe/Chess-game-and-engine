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
