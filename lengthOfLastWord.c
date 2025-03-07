int lengthOfLastWord(char* s)
{
    int last_word = 0;
    int i = 0;
    
    while (s[i] != '\0')
    {
        if (s[i] != ' ')
        {
            last_word = 0;
            while (s[i] != '\0' && s[i] != ' ')
            {
                ++last_word;
                ++i;
            }
        }
        else
        {
            ++i;
        }
    }

    return last_word;
}