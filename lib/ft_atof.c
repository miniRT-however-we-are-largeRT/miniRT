#include "libft.h"
#include <math.h>

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

double	ft_atod(const char *str)
{
	double	result;
	double	sign;
	double	decimal;
	double	decimal_divisor;
	int		i;

	result = 0;
	sign = 1;
	decimal = 0;
	decimal_divisor = 1; // 소수부의 나눗셈 값을 누적할 변수
	i = 0;
	// 공백 무시
	while (ft_isspace(str[i]))
		i++;
	// 부호 처리
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	// 정수부 계산
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	// 소수부 계산
	if (str[i] == '.')
	{
		i++;
		while (ft_isdigit(str[i]))
		{
			decimal = decimal * 10 + (str[i] - '0');
			decimal_divisor *= 10; // 소수점 자릿수를 반영
			i++;
		}
	}
	// 최종 결과 반환
	return (sign * (result + decimal / decimal_divisor));
}
