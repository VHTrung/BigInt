#include <iostream>
#include <fstream>
#include "Integer.h"

using namespace std;
int main(int _argc, char ** _argv)
{
	string substr1, substr2;
	if (_argc != 3)
		return 0;
	cout << "Arguments are valid.\n";
	fstream in, out;

	in.open(_argv[1], ios_base::in);
	if (!in.good())
		return -1;
	cout << "Open input file successfully.\n";

	out.open(_argv[2], ios_base::out);
	if (!out.good())
		return -2;
	cout << "Open output file successfully.\n";

	unsigned int inRadix;
	while ((in >> inRadix) && false || !in.eof())
	{
		in.ignore(130, ' ');

		in >> substr1;
		in >> substr2;

		switch (substr2[0])
		{
		case '~':
		{
			Integer result(substr2, inRadix);
			result.ShrinkToFit();
			out << (~result).GetValue(inRadix) << endl;
			cout << "Operator ~.\n";
			break;
		}
		case '+':
		{
			in >> substr2;
			Integer lhs(substr1, inRadix), rhs(substr2, inRadix);
			switch (inRadix)
			{
			case 2:
				out << (lhs + rhs).GetBinValue() << endl;
				break;
			case 8:
				out << (lhs + rhs).GetOctValue() << endl;
				break;
			case 10:
				out << (lhs + rhs).GetDecValue() << endl;
				break;
			case 16:
				out << (lhs + rhs).GetHexValue() << endl;
				break;
			default:
				break;
			}
			cout << "Operator +.\n";
			break;
		}
		case '-':
		{
			if (substr2.size() == 1)//minus sign
			{
				in >> substr2;
				Integer lhs(substr1,inRadix), rhs(substr2,inRadix);
				out << (lhs - rhs).GetValue(inRadix) << endl;
				cout << "Operator -.\n";
			}
			else
			{
				if (substr1[0] == '1' || substr1[0] == '2' || substr1[0] == '8')//signed of decimal
				{
					unsigned int outRadix;
					outRadix = atoi(substr1.c_str());
					Integer result(substr2, inRadix);
					out << result.GetValue(outRadix) << endl;
					cout << "Convert radix to " << outRadix << ".\n";
				}
				else if (substr1[0] == '~')
				{
					Integer result(substr2, inRadix);
					result.ShrinkToFit();
					out << (~result).GetValue(inRadix) << endl;
					cout << "Operator ~.\n";
				}
			}

			break;
		}
		case '*':
		{
			in >> substr2;
			Integer lhs(substr1, inRadix), rhs(substr2, inRadix);
			out << (lhs * rhs).GetValue(inRadix) << endl;
			cout << "Operator *.\n";
			break;
		}
		case '/':
		{
			in >> substr2;
			Integer lhs(substr1, inRadix), rhs(substr2, inRadix);
			if (rhs.GetValue(16) != "0")
			{
				out << (lhs / rhs).GetValue(inRadix) << endl;
				cout << "Operator /.\n";
			}
			else
			{
				out << "NaN\n";
				cout << "Operator /. Devide by zero\n";
			}
			break;
		}
		case '&':
		{
			in >> substr2;
			Integer lhs(substr1, inRadix), rhs(substr2, inRadix);
			out << (lhs & rhs).GetValue(inRadix) << endl;
			cout << "Operator &.\n";
			break;
		}
		case '|':
		{
			in >> substr2;
			Integer lhs(substr1, inRadix), rhs(substr2, inRadix);
			out << (lhs | rhs).GetValue(inRadix) << endl;
			cout << "Operator |.\n";
			break;
		}
		case '^':
		{
			in >> substr2;
			Integer lhs(substr1, inRadix), rhs(substr2, inRadix);
			out << (lhs ^ rhs).GetValue(inRadix) << endl;
			cout << "Operator ^.\n";
			break;
		}
		case '>':
		{
			if (substr2 == string(">>"))
			{
				int amount;
				in >> amount;
				Integer lhs(substr1, inRadix);
				out << (lhs >> amount).GetValue(inRadix) << endl;
				cout << "Operator >>.\n";
			}
			break;
		}
		case '<':
		{
			if (substr2 == string("<<"))
			{
				int amount;
				in >> amount;
				Integer lhs(substr1, inRadix);
				out << (lhs << amount).GetValue(inRadix) << endl;
				cout << "Operator <<.\n";
			}
			break;
		}
		case 'r':
		{
			if (substr2 == string("rol"))
			{
				int amount;
				in >> amount;
				Integer lhs(substr1, inRadix);
				out << lhs.RotateLeft(amount).GetValue(inRadix) << endl;
				cout << "Operator rol.\n";
			}
			else if (substr2 == string("ror"))
			{
				int amount;
				in >> amount;
				Integer lhs(substr1, inRadix);
				out << lhs.RotateRight(amount).GetValue(inRadix) << endl;
				cout << "Operator ror.\n";
			}
			break;
		}
		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
		case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
		case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
			if (substr1[0] == '1' || substr1[0] == '2' || substr1[0] == '8')
			{
				unsigned int outRadix;
				outRadix = atoi(substr1.c_str());
				Integer result(substr2, inRadix);
				result.ShrinkToFit();
				out << result.GetValue(outRadix) << endl;
				cout << "Convert radix to " << outRadix << ".\n";
			}
			else if (substr1[0] == '~')
			{
				Integer result(substr2, inRadix);
				result.ShrinkToFit();
				out << (~result).GetValue(inRadix) << endl;
				cout << "Operator ~.\n";
			}
			else if (substr1 == string("rol"))
			{
				Integer lhs( substr1,inRadix);
				out << lhs.RotateLeft().GetValue(inRadix) << endl;
				cout << "Operator rol.\n";
			}
			else if (substr1 == string("ror"))
			{
				Integer lhs(substr2, inRadix);
				out << lhs.RotateRight().GetValue(inRadix) << endl;
				cout << "Operator ror.\n";
			}
			break;
		default:
			break;
		}
	}

	in.close();
	out.close();
	return 1;
}