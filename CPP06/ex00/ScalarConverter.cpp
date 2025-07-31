#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) 
{
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) 
{
	if (this != &copy)
	{
		// No members to copy, but this is here for completeness
	}
	return *this;
}

static bool isDisplayable(char c) 
{
	return (c >= 32 && c <= 126);
}

void ScalarConverter::convert(const std::string& literal)
{
	double val;

	// Stringe bak, özel durumlar için kontrolleri yap
	if (literal == "nan" || literal == "nanf")
		val = std::numeric_limits<double>::quiet_NaN(); //NaN değerini alır
	else if (literal == "+inf" || literal == "+inff")
		val = std::numeric_limits<double>::infinity();

	else if (literal == "-inf" || literal == "-inff")
		val = -std::numeric_limits<double>::infinity();
	else if (literal.length() == 1 && !std::isdigit(literal[0]))
	{
		char c = literal[0];
		val = static_cast<double>(c);
	} //Sayı gibi bir şey gelirse
	else
	{
		char *endPtr;
		val = std::strtod(literal.c_str(), &endPtr); //sayıyı double'a çevir, endptr'ye çevirmeyi nerde bıraktıysa oranın adresini ver

		if (endPtr && *endPtr != '\0') //Eğer endptr'de nulldan başka bir şey varsa geçersizdir.
		{
			std::cerr << "char: impossible" << std::endl;
			std::cerr << "int: impossible" << std::endl;
			std::cerr << "float: impossible" << std::endl;
			std::cerr << "double: impossible" << std::endl;
			return ;
		}
	}

	std::cout << "char: ";
	if (std::isnan(val) || std::isinf(val) || val < 0 || val > 127) //Char basılacağı zaman val 0-127 arası olmalıdır, diğer türlü char yoktur ve overflow olur. Bu sebeple impossible bastılır
		std::cout << "impossible" << std::endl;
	else if (!isDisplayable(static_cast<int>(val)))
		std::cout << "Non displayable" << std::endl; //Displayable bir char değilse ona göre mesaj basılır
	else
		std::cout << "'" << static_cast<char>(val) << "'" << std::endl; //Değer char'a castlenir ve ekrana basılır.

	std::cout << "int: ";
	if (std::isnan(val) || std::isinf(val) || val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max()) //Aynı overflow durumu.
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(val) << std::endl;
	
	std::cout << "float: ";
	std::cout << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f" << std::endl;

	std::cout << "double: ";
	std::cout << std::fixed << std::setprecision(1) << val << std::endl;
}