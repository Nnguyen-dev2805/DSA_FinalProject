#include<iostream>
#include<string>
#include<stack>
#include<cmath>

using namespace std; 
// lấy độ ưu tiên
int Precedence(char op) {
	if (op == '+' || op == '-') return 1;
	else if (op == '*' || op == '/'||op=='%') return 2;
	else if (op == '^') return 3;
	return 0;
}

bool isOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%';
}


string standadize(string &infix) {
	infix.erase(remove(infix.begin(), infix.end(), ' '),infix.end());
	return infix;
}



string InfixToPosFix(string infix) {
	standadize(infix); // chuan hoa lai bieu thuc, xoa casc khoang trang thua
	stack<char>op; // stack luu toan tu
	string posfix = ""; // ket qua bieu thux sau khi chuyen 
	for (int i = 0; i < infix.size(); i++) {
		char c = infix[i];
		// kiem tra la so va so am, phan biet dau am va dau '-'
		if (isalnum(c) || c == '.'||(c == '-' && (i == 0 || !isalnum(infix[i - 1]) && infix[i - 1] != ')'))){
			posfix += c;
			// tach cac phan tu rieng biet bang khoang trang
			if (i == infix.size() - 1 || (!isalnum(infix[i + 1]) && infix[i + 1] != '.')) {
				posfix = posfix + " ";
			}
		}
		else {
			if (c == '(') op.push(c); // Gap dau '(' them thang vao stack
			else {
				if (c == ')') {
					// nếu là dấu đóng ngoặc chuyển hết các op có trong khaongr () trong stack qua posfix
					while (!op.empty() && op.top() != '(') {
						posfix += op.top();
						posfix += " ";
						op.pop();
					}
					 if(!op.empty()) op.pop(); // xóa dấu ngoặc ra khỏi stack
				}
				else {
					if (isOperator(c)) {
						// xét độ ưu tiên của toán tử
						// nếu nhỏ hơn hơn op.top() thì posfix += top
							while (!op.empty() && Precedence(op.top()) >= Precedence(c)) {
								posfix += op.top();
								posfix += " ";
								op.pop();
							}
						op.push(c); // thêm toán tử đang xét vào stack
					}
				}
			}
		}
	}
	// Đưa tất cả toán tử vào kết quả 
	while (!op.empty()) {
		posfix += op.top();
		posfix += " ";
		op.pop();
	}
	return posfix;
}

// tinh ket qua khi truyen vao bieu thuc posfix
string ResultPosFix(string posfix) {
	stack<double>st; // Luu cac thanh phan so va ket qua cua cac phep tinh nho
	int i;
	for (i = 0; i < posfix.size(); i++) {
		if (posfix[i] == ' ') continue;
		else {
			if (isalpha(posfix[i])) return "0";
			if (isdigit(posfix[i]) || posfix[i] == '.'||(posfix[i]=='-' && isdigit(posfix[i+1])))
			{
				string num="";
				while (i<posfix.size()&&(isdigit(posfix[i]) || posfix[i] == '.' || (posfix[i] == '-' &&isdigit(posfix[i + 1])))) {
					num += posfix[i];
					i++;
				}
				i--; // dua con tro ve dung vi tri
				double number = stod(num); 
				st.push(number);
			}
			else {
				// Neu khong du toan hang de thuc hien phep tinh 
				if (st.size() < 2) {
					return "Bieu thuc khong hop le";
				}
				double val1 = st.top();
				st.pop();
				double val2 = st.top();
				st.pop();
				switch (posfix[i])
				{
				case '+': {
					st.push(val2 + val1);
					break;
				}
				case '-': {
					st.push(val2 - val1);
					break;
				}
				case '*': {
					st.push(val2 * val1);
					break;
				}
				case '/': {
					double x = double(val2) / val1;
					st.push(x);
					break;
				}
				case '%': {
					st.push(fmod(val2, val1));
					break;
				}
				case '^': {
					st.push(pow(val2, val1));
					break;
				}
				default:
					return "Bieu thuc khong hop le";
				}
			}
		}
	}
	// Neu con nhieu hon 1 phan tu trong stack, bieu thuc khong hop le
	if (st.size() != 1) return "Bieu thuc khong hop le";
	return to_string(st.top());
}



int main() {
	while (true) {
		string infix, posfix, result; 
		cout << "Enter infix: ";
		getline(cin, infix);
		standadize(infix);
		posfix = InfixToPosFix(infix);
		result = ResultPosFix(posfix);
		cout << "Infix: " << infix << endl;
		cout << "Posfix: " << posfix << endl;
		if (!result.empty() && isdigit(result[0])) {
			cout << "Result: ";
		}
		cout << result << endl << endl;
		cout << "Continue (Y/N)?"; 
		char x; 
		cin >> x;
		cin.ignore();
		if (x != 'Y' && x != 'y') {
			return 0;
		}
	}
	return 0;
}