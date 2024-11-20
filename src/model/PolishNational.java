package model;

import java.util.Stack;

public class PolishNational {
    String Infix;

    public PolishNational(String Infix) {
        this.Infix = Infix;
    }

    public PolishNational() {
        this.Infix = "";
    }

    public String getInfix() {
        return Infix;
    }
    public void setInfix(String Infix) {
        this.Infix = Infix;
    }

    // ham xoa kkhoang trang thua
    public String removeSpace(String s){
        if (s == null || s.isEmpty()) {
            throw new IllegalArgumentException("Biểu thức không hợp lệ");
        }
        return s.replaceAll("\\s+", ""); // Loại bỏ tất cả khoảng trắng
    }

    public static int Precedence(char op){
        if(op=='+'||op=='-') return 1;
        if(op=='*'||op=='/'||op=='%') return 2;
        if(op=='^') return 3;
        return 0;
    }

    public static boolean isOperator(char op){
        return op == '+' || op == '-' || op == '*' || op == '/' || op == '%' || op == '^';
    }

    public String InfixtoPosfix(){
        Infix=removeSpace(Infix); // chuan hoa lai bieu thuc, xoa casc khoang trang thua
        Stack<Character> op = new Stack<>(); // stack luu toan tu
        StringBuilder posfix = new StringBuilder(); // ket qua bieu thux sau khi chuyen
        for(int i=0; i<Infix.length(); i++){
            char c = Infix.charAt(i);
            // kiem tra la so va so am, phan biet dau am va dau '-'
            if((Character.isLetter(c) || Character.isDigit(c)) || c=='.' ||
                    (c=='-' && (i==0 || ( (!Character.isLetter(Infix.charAt(i-1)) && !Character.isDigit(Infix.charAt(i-1)))&& Infix.charAt(i-1)!=')')))){
                posfix.append(c);
                // tach cac phan tu rieng biet bang khoang trang
                if(i==Infix.length()-1||((!Character.isDigit(Infix.charAt(i+1))&&!Character.isLetter(Infix.charAt(i+1)))&&Infix.charAt(i+1) != '.')){
                        posfix.append(" ");
                }
            }
            else{
                if(c=='(') op.push(c);  // Gap dau '(' them thang vao stack
                else{
                    if(c==')'){
                        // nếu là dấu đóng ngoặc chuyển hết các op có trong khaong () trong stack qua posfix
                        while(!op.isEmpty() && op.peek()!='('){
                            posfix.append(op.peek());
                            posfix.append(" ");
                            op.pop();
                        }
                        if (!op.isEmpty()) op.pop(); // xoa dau ngoac ra khoi stack
                    }
                    else{
                        if(isOperator(c)){
                            // xét độ ưu tiên của toán tử
                            // nếu nhỏ hơn hơn op.top() thì posfix += top
                            while (!op.empty() && Precedence(op.peek()) >= Precedence(c)) {
                                posfix.append(op.peek());
                                posfix.append(" ");
                                op.pop();
                            }
                            op.push(c); // thêm toán tử đang xét vào stack
                        }
                    }
                }
            }
        }
        // Đưa tất cả toán tử vào kết quả
        while(!op.isEmpty()){
            posfix.append(op.peek());
            posfix.append(" ");
            op.pop();
        }

        return posfix.toString().trim();
    }

    // tinh ket qua khi truyen vao bieu thuc posfix
    public String ResultPosfix(String Posfix){
        Stack<Double> st = new Stack<>(); // Luu cac thanh phan so va ket qua cua cac phep tinh nho
        int i;
        for(i=0; i<Posfix.length(); i++){
            if(Posfix.charAt(i)==' ') continue;
            if(Character.isLetter(Posfix.charAt(i))) return "0";
            if((Character.isDigit(Posfix.charAt(i)) || (Posfix.charAt(i)=='.' ) ||
                    (Posfix.charAt(i)=='-' && i<Posfix.length()-1 && Character.isDigit(Posfix.charAt(i+1))))) {
                StringBuilder num = new StringBuilder();
                while ( i<Posfix.length() && (Character.isDigit(Posfix.charAt(i)) || (Posfix.charAt(i)=='.' ) ||
                        (Posfix.charAt(i)=='-' && Character.isDigit(Posfix.charAt(i+1))))){
                    num.append(Posfix.charAt(i));
                    i++;
                }
                i--; // dua con tro ve dung vi tri
                Double number=Double.valueOf(num.toString());
                st.push(number);
            }
            else{
                // Neu khong du toan hang de thuc hien phep tinh
                if (st.size() < 2) {
                    return "Bieu thuc khong hop le";
                }
                double val1 = st.peek();
                st.pop();
                double val2 = st.peek();
                st.pop();
                switch (Posfix.charAt(i))
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
/*
                        if (val1 == 0) {
                            throw new ArithmeticException("Lỗi: Chia cho 0.");
                        }
*/
                        double x = val2 / val1;
                        st.push(x);
                        break;
                    }
                    case '%': {
                        st.push(val2%val1);
                        break;
                    }
                    case '^': {
                        st.push(Math.pow(val2, val1));
                        break;
                    }
                    default:
                        return "Bieu thuc khong hop le";
                }
            }
        }

        // Neu con nhieu hon 1 phan tu trong stack, bieu thuc khong hop le
        if(st.size()!=1)  return "Bieu thuc khong hop le";
        return String.valueOf(st.peek());
    }
}
