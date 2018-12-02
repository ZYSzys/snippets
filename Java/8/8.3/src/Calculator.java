import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.Vector;

public class Calculator
{
    String str1 = "0";
    String str2 = "0";
    String symbol = "+";
    String result = "";
    int key = 1;  //输入开关，为1时输入前一个数，为2时输入后一个数
    int count_symbol = 1; //判断是否为多重运算并计数
    int flag1 = 1; //判断前一个数能否重置为0
    int flag2 = 1; //判断后一个数能否重置为0
    int dot = 1; //对小数点进行判断
    JButton store; //存储运算符按键

    Vector vt = new Vector(20, 10); //多重运算时存储运算符按键

    JFrame frame = new JFrame("Calculator");
    JTextField result_tf = new JTextField(result);
    JButton button0 = new JButton("0");
    JButton button1 = new JButton("1");
    JButton button2 = new JButton("2");
    JButton button3 = new JButton("3");
    JButton button4 = new JButton("4");
    JButton button5 = new JButton("5");
    JButton button6 = new JButton("6");
    JButton button7 = new JButton("7");
    JButton button8 = new JButton("8");
    JButton button9 = new JButton("9");
    JButton button_dot = new JButton(".");
    JButton button_plus = new JButton("+");
    JButton button_cut = new JButton("-");
    JButton button_mul = new JButton("*");
    JButton button_mod = new JButton("/");
    JButton button_equ = new JButton("=");

    public Calculator()
    {
        result_tf.setHorizontalAlignment(JTextField.RIGHT);

        JPanel pan = new JPanel();
        pan.setLayout(new GridLayout(4, 4, 5, 5));
        pan.add(button7);
        pan.add(button8);
        pan.add(button9);
        pan.add(button_plus);
        pan.add(button4);
        pan.add(button5);
        pan.add(button6);
        pan.add(button_cut);
        pan.add(button1);
        pan.add(button2);
        pan.add(button3);
        pan.add(button_mul);
        pan.add(button0);
        pan.add(button_dot);
        pan.add(button_equ);
        pan.add(button_mod);
        pan.setBorder(BorderFactory.createEmptyBorder(5, 5, 5, 5));

        JPanel pan2 = new JPanel();
        pan2.setLayout(new BorderLayout());
        pan2.add(result_tf, BorderLayout.CENTER);

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setResizable(false);
        frame.getContentPane().setLayout(new BorderLayout());
        frame.getContentPane().add(pan2, BorderLayout.NORTH);
        frame.getContentPane().add(pan, BorderLayout.CENTER);
        frame.pack();
        frame.setVisible(true);

        //数字按键事件监听
        class Listener implements ActionListener
        {
            public void actionPerformed(ActionEvent e)
            {
                String temp = ((JButton) e.getSource()).getText();
                store = (JButton) e.getSource();
                vt.add(store);
                if (key == 1)
                {
                    if (flag1 == 1)
                    {
                        str1 = "";
                        dot = 1;
                    }
                    str1 = str1 + temp;
                    flag1 = flag1 + 1;
                    result_tf.setText(str1);
                }
                else if (key == 2)
                {
                    if (flag2 == 1)
                    {
                        str2 = "";
                        dot = 1;
                    }
                    str2 = str2 + temp;
                    flag2 = flag2 + 1;
                    result_tf.setText(str2);
                }
            }
        }
        //运算符按键事件监听
        class Listener_symbol implements ActionListener
        {
            public void actionPerformed(ActionEvent e)
            {
                String temp = ((JButton) e.getSource()).getText();
                store = (JButton) e.getSource();
                vt.add(store);
                if (count_symbol == 1)
                {
                    key = 2;
                    dot = 1;
                    symbol = temp;
                    count_symbol = count_symbol + 1;
                }
                else
                {
                    //多重运算处理
                    int a = vt.size();
                    JButton c = (JButton) vt.get(a - 2);
                    if (!(c.getText().equals("+")) && !(c.getText().equals("-")) && !(c.getText().equals("*")) && !(c.getText().equals("/")))
                    {
                        cal();
                        str1 = result;
                        key = 2;
                        dot = 1;
                        flag2 = 1;
                        symbol = temp;
                    }
                    count_symbol = count_symbol + 1;
                }
            }
        }
        //"="按键事件
        class Listener_equ implements ActionListener
        {
            public void actionPerformed(ActionEvent e)
            {
                store = (JButton) e.getSource();
                vt.add(store);
                cal();
                key = 1;
                count_symbol = 1;
                flag1 = 1;
                flag2 = 1;
                str1 = result;
            }
        }
        //"."按键事件
        class Listener_dot implements ActionListener
        {
            public void actionPerformed(ActionEvent e)
            {
                store = (JButton) e.getSource();
                vt.add(store);
                if (dot == 1)
                {
                    String temp = ((JButton) e.getSource()).getText();
                    if (key == 1)
                    {
                        if (flag1 == 1)
                        {
                            str1 = "";
                            dot = 1;
                        }
                        str1 = str1 + temp;
                        flag1 = flag1 + 1;
                        result_tf.setText(str1);
                    }
                    else if (key == 2)
                    {
                        if (flag2 == 1)
                        {
                            str2 = "";
                            dot = 1;
                        }
                        str2 = str2 + temp;
                        flag2 = flag2 + 1;
                        result_tf.setText(str2);
                    }
                }
                dot = dot + 1;
            }
        }

        button0.addActionListener(new Listener());
        button1.addActionListener(new Listener());
        button2.addActionListener(new Listener());
        button3.addActionListener(new Listener());
        button4.addActionListener(new Listener());
        button5.addActionListener(new Listener());
        button6.addActionListener(new Listener());
        button7.addActionListener(new Listener());
        button8.addActionListener(new Listener());
        button9.addActionListener(new Listener());
        button_dot.addActionListener(new Listener_dot());
        button_plus.addActionListener(new Listener_symbol());
        button_cut.addActionListener(new Listener_symbol());
        button_mul.addActionListener(new Listener_symbol());
        button_mod.addActionListener(new Listener_symbol());
        button_equ.addActionListener(new Listener_equ());
    }

    public void cal()
    {
        double n1;
        double n2;
        if (str1.equals("."))
        str1 = "0.0";
        if (str2.equals("."))
            str2 = "0.0";
        n1 = Double.valueOf(str1).doubleValue();
        n2 = Double.valueOf(str2).doubleValue();

        String c = symbol;
        double ans = 0;
        if (c.equals(""))
        {
            result_tf.setText("Please input operator");

        } else
        {
            if (c.equals("+"))
                ans = n1 + n2;
            else if (c.equals("-"))
                ans = n1 - n2;
            else if (c.equals("*"))
                ans = n1 * n2;
            else if (c.equals("/"))
            {
                if (n2 == 0)
                    ans = 0;
                else
                    ans = n1 / n2;
            }
            result = ((new Double(ans)).toString());
            result_tf.setText(result);
        }
    }

    public static void main(String[] args)
    {
        Calculator cal = new Calculator();
    }
}