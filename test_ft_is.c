/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_is.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verosvec <verosvec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 17:07:50 by verosvec          #+#    #+#             */
/*   Updated: 2026/09/18 14:17:06 by verosvec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void	run_char_test(char *label, int expected, int actual)
{
	if (expected == actual)
		printf("PASS: %s\n", label);
	else
		printf("FAIL: %s (expected %d, got %d)\n", label, expected, actual);
}

void	test_ft_isalpha(void)
{
	printf("--- ft_isalpha ---\n");
	run_char_test("lowercase letter", (isalpha('a') != 0), ft_isalpha('a'));
	run_char_test("uppercase letter", (isalpha('Z') != 0), ft_isalpha('Z'));
	run_char_test("digit", (isalpha('5') != 0), ft_isalpha('5'));
	run_char_test("space", (isalpha(' ') != 0), ft_isalpha(' '));
	run_char_test("symbol", (isalpha('!') != 0), ft_isalpha('!'));
	run_char_test("control char", (isalpha('\n') != 0), ft_isalpha('\n'));
	run_char_test("out of range", (isalpha(200) != 0), ft_isalpha(200));
}

void	test_ft_isdigit(void)
{
	printf("--- ft_isdigit ---\n");
	run_char_test("lowercase letter", (isdigit('a') != 0), ft_isdigit('a'));
	run_char_test("uppercase letter", (isdigit('Z') != 0), ft_isdigit('Z'));
	run_char_test("digit", (isdigit('5') != 0), ft_isdigit('5'));
	run_char_test("space", (isdigit(' ') != 0), ft_isdigit(' '));
	run_char_test("symbol", (isdigit('!') != 0), ft_isdigit('!'));
	run_char_test("control char", (isdigit('\n') != 0), ft_isdigit('\n'));
	run_char_test("out of range", (isdigit(200) != 0), ft_isdigit(200));
}

void	test_ft_isalnum(void)
{
	printf("--- ft_isalnum ---\n");
	run_char_test("lowercase letter", (isalnum('a') != 0), ft_isalnum('a'));
	run_char_test("uppercase letter", (isalnum('Z') != 0), ft_isalnum('Z'));
	run_char_test("digit", (isalnum('5') != 0), ft_isalnum('5'));
	run_char_test("space", (isalnum(' ') != 0), ft_isalnum(' '));
	run_char_test("symbol", (isalnum('!') != 0), ft_isalnum('!'));
	run_char_test("control char", (isalnum('\n') != 0), ft_isalnum('\n'));
	run_char_test("out of range", (isalnum(200) != 0), ft_isalnum(200));
}

void	test_ft_isascii(void)
{
	printf("--- ft_isascii ---\n");
	run_char_test("lowercase letter", (isascii('a') != 0), ft_isascii('a'));
	run_char_test("uppercase letter", (isascii('Z') != 0), ft_isascii('Z'));
	run_char_test("digit", (isascii('5') != 0), ft_isascii('5'));
	run_char_test("space", (isascii(' ') != 0), ft_isascii(' '));
	run_char_test("symbol", (isascii('!') != 0), ft_isascii('!'));
	run_char_test("control char", (isascii('\n') != 0), ft_isascii('\n'));
	run_char_test("out of range", (isascii(200) != 0), ft_isascii(200));
}

void	test_ft_isprint(void)
{
	printf("--- ft_isprint ---\n");
	run_char_test("lowercase letter", (isprint('a') != 0), ft_isprint('a'));
	run_char_test("uppercase letter", (isprint('Z') != 0), ft_isprint('Z'));
	run_char_test("digit", (isprint('5') != 0), ft_isprint('5'));
	run_char_test("space", (isprint(' ') != 0), ft_isprint(' '));
	run_char_test("symbol", (isprint('!') != 0), ft_isprint('!'));
	run_char_test("control char", (isprint('\n') != 0), ft_isprint('\n'));
	run_char_test("out of range", (isprint(200) != 0), ft_isprint(200));
}

void	test_ft_toupper(void)
{
	printf("--- ft_toupper ---\n");
	run_char_test("lowercase letter", toupper('a'), ft_toupper('a'));
	run_char_test("uppercase letter", toupper('A'), ft_toupper('A'));
	run_char_test("digit", toupper('5'), ft_toupper('5'));
	run_char_test("space", toupper(' '), ft_toupper(' '));
	run_char_test("symbol", toupper('!'), ft_toupper('!'));
}

void	test_ft_tolower(void)
{
	printf("--- ft_tolower ---\n");
	run_char_test("uppercase letter", tolower('A'), ft_tolower('A'));
	run_char_test("lowercase letter", tolower('a'), ft_tolower('a'));
	run_char_test("digit", tolower('5'), ft_tolower('5'));
	run_char_test("space", tolower(' '), ft_tolower(' '));
	run_char_test("symbol", tolower('!'), ft_tolower('!'));
}
