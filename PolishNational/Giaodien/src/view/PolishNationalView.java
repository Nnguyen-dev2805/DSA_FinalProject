package view;

import contronller.PolishNationalAction;
import model.PolishNational;
import javax.swing.*;
import java.awt.*;


// tạo class PolishNationalView kết thừa từ JFrame
public class PolishNationalView extends JFrame {
    private PolishNational balan; // bieu thuc polishNational
    private JTextField textInfix; // Ô cho phép người dùng nhập dữ liệu
    private JTextField LabelPosfix; // Ô in ra kết quả khi chuyển từ infix sang posfix
    private JTextField LabelResult; // Ô in kết quả của biểu thức
    private JButton buttonEnter; // nút bấm Enter
    private JButton buttonClear; // nút bấm Clear

    public PolishNationalView() {
        init();
        this.pack(); // tự căn chỉnh
        this.setVisible(true); // cho phép màm hình đồ họa xuất hiện
    }

    public void init(){
        this.setTitle("Polish National"); // xét tiêu đề cho màm hình giao diện
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // chuong trình kết thức khoi close
        this.setPreferredSize(new Dimension(600, 250)); // Đặt kích thước tối đa
        this.setLocationRelativeTo(null); // cho man hình xuất hiện ở giữa

        // tao phong chu, kich co cho bieu thuc
        Font font = new Font("Arial", Font.BOLD|Font.ITALIC, 15);

        // yeu cap nhap
        JButton ButtonFirst=new JButton("Enter Infix: ");
        ButtonFirst.setFont(font); // xét phông chữ
        ButtonFirst.setBorder(BorderFactory.createLineBorder(Color.BLACK)); // xét viền

        JButton ButtonSecond=new JButton(" Posfix: ");
        ButtonSecond.setFont(font);
        ButtonSecond.setBorder(BorderFactory.createLineBorder(Color.BLACK));

        JButton ButtonThird=new JButton("Result: ");
        ButtonThird.setFont(font);
        ButtonThird.setBorder(BorderFactory.createLineBorder(Color.BLACK));


        textInfix = new JTextField("",25);
        textInfix.setFont(font);
        textInfix.setPreferredSize(new Dimension(200, 25));
        //textInfix.setBorder(BorderFactory.createLineBorder(Color.BLACK));
        LabelPosfix = new JTextField("",25);
        LabelPosfix.setFont(font);
        LabelPosfix.setPreferredSize(new Dimension(200, 25));
        //LabelPosfix.setBorder(BorderFactory.createLineBorder(Color.BLACK));
        LabelResult = new JTextField("",25);
        LabelResult.setFont(font);
        LabelResult.setPreferredSize(new Dimension(200, 25));
        //LabelResult.setBorder(BorderFactory.createLineBorder(Color.BLACK));

        // tạo khung chứa các button yêu cầu nhập thông tin
        JPanel panelButton = new JPanel(new GridLayout(3,1,10,10)); // khung theo dạng lưới
        panelButton.add(ButtonFirst);
        panelButton.add(ButtonSecond);
        panelButton.add(ButtonThird);

        // Tạo khung chứa các Text chứa khiung người nhập và kết quả của chuong trình
        JPanel panelText = new JPanel(new GridLayout(3,1,10,10)); // khung theo dạg lưới
        panelText.add(textInfix);
        panelText.add(LabelPosfix);
        panelText.add(LabelResult);

        // Tạo 1 khung chứa 2 panel đá tạo ở trên
        JPanel panelIO = new JPanel(new BorderLayout(10,10)); // khung theo dạng đông, tây, nam, bắc và giữa
        panelIO.add(panelButton, BorderLayout.WEST); // thêm khụng botton vào West
        panelIO.add(panelText, BorderLayout.CENTER); // thêm khung Jtext vào giữa




        this.setLayout(new BorderLayout(10,10)); // tạo màn hình
        this.add(panelIO, BorderLayout.CENTER); // thêm vào panel vào giữa màn hình

        PolishNationalAction act=new PolishNationalAction(this); // tạo sự kiện cho nút bấm Clear và Enter

        buttonEnter = new JButton("Enter");
        //buttonEnter.setBounds(10,10,200,100);
        buttonEnter.setPreferredSize(new Dimension(80, 35));
        buttonEnter.setFont(new Font("Arial", Font.BOLD|Font.ITALIC, 15));
        buttonEnter.addActionListener(act); // thêm vào button để xử lý sự kiện
        //buttonEnter.setBorder(BorderFactory.createLineBorder(Color.BLACK));

        buttonClear = new JButton("Clear");
        //buttonClear.setBounds(150,10,200,100);
        buttonClear.setPreferredSize(new Dimension(80, 35));
        buttonClear.setFont(new Font("Arial", Font.BOLD|Font.ITALIC, 15));
        buttonClear.addActionListener(act); // thêm vào button để xử lý sự kiện
        //buttonClear.setBorder(BorderFactory.createLineBorder(Color.BLACK));

        JPanel panelButtons = new JPanel(new FlowLayout(FlowLayout.CENTER, 20, 15)); // FlowLayout cho phép dễ dàng chỉnh kích thước
        panelButtons.add(buttonEnter);
        panelButtons.add(buttonClear);

        // thêm các panel trống để các  ô giữa cách viền 1 khoảng trống
        JPanel haha1 = new JPanel(new FlowLayout(FlowLayout.CENTER, 20, 15));
        JPanel haha2 = new JPanel(new FlowLayout(FlowLayout.CENTER, 20, 15));
        JPanel haha3 = new JPanel(new FlowLayout(FlowLayout.CENTER, 20, 15));
        this.add(haha1, BorderLayout.NORTH);
        this.add(haha2, BorderLayout.EAST);
        this.add(haha3, BorderLayout.WEST);
        this.add(panelButtons, BorderLayout.SOUTH);
    }

    // xử lý sự kiện khi bấm vào Enter
    public void ClickEnter(){
        this.balan = new PolishNational();
        String infix = textInfix.getText();
        balan.setInfix(infix);
        String posfix= balan.InfixtoPosfix();
        String result=balan.ResultPosfix(posfix);
        if(result.equals("Bieu thuc khong hop le")){
            JOptionPane.showMessageDialog(this, "Error! Wrong expression");
            LabelPosfix.setText("");
            LabelResult.setText("");
            textInfix.setText("");
        }
        else{
            LabelPosfix.setText(posfix);
            LabelResult.setText(result);
        }
    }

    // xử lý sự khi bấm vào
    public void ClickClear(){
        LabelPosfix.setText("");
        LabelResult.setText("");
        textInfix.setText("");
    }

}
