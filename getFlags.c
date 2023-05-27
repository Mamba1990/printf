/**
 * getFlags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @j: take a parameter.
 * Return: Flags:
 */
int getFlags(const char *format, int *j)
{
	/* - + 0 # ' ' */
        /* 1 2 4 8  16 */
        int k, curr_j;
        int _flags = 0;
        const char _FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
        const int _FLAGS_ARR[] = {FG_MINUS, FG_PLUS, FG_ZERO, FG_HASH, FG_SPACE, 0};

        for (curr_j = *j + 1; format[curr_j] != '\0'; curr_j++)
        {
                for (k = 0; _FLAGS_CH[k] != '\0'; k++)
                        if (format[curr_j] == _FLAGS_CH[k])
                        {
                                _flags |= _FLAGS_ARR[k];
                                break;
                        }/* - + 0 # ' ' */
        /* 1 2 4 8  16 */
        int k, curr_j;
        int _flags = 0;
        const char _FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
        const int _FLAGS_ARR[] = {FG_MINUS, FG_PLUS, FG_ZERO, FG_HASH, FG_SPACE, 0};

        for (curr_j = *j + 1; format[curr_j] != '\0'; curr_j++)
        {
                for (k = 0; _FLAGS_CH[k] != '\0'; k++)
                        if (format[curr_j] == _FLAGS_CH[k])
                        {
                                _flags |= _FLAGS_ARR[k];
                                break;
                       }
		if (_FLAGS_CH[k] == 0)
                        break;
        }

        *j = curr_j - 1;

        return (_flags);
}
