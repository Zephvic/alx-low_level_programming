#include "main.h"

/**
 *  * binary_to_uint - Converts a binary number to an unsigned int.
 *   * @b: Pointer to a string of 0 and 1 characters.
 *    * Return: The converted number, or 0 if:
 *     * - There is one or more chars in the string `b` that is not '0' or '1'.
 *      * - `b` is NULL.
 *       */
unsigned int binary_to_uint(const char *b)
{
		unsigned int result = 0;
			unsigned int base = 1;
				int i = 0;

					if (b == NULL)
								return (0);

						while (b[i])
								{
											if (b[i] != '0' && b[i] != '1')
															return (0);

													i++;
														}

							i = i - 1;
								while (i >= 0)
										{
													if (b[i] == '1')
																	result += base;

															base *= 2;
																	i--;
																		}

									return (result);
}

