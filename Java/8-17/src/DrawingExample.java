import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class DrawingExample implements ActionListener {
    JFrame frame;
    MyButton button;
    MyPanel panel;
    int tag = 1;

    public static void main(String[] args) {
        DrawingExample de = new DrawingExample();
        de.go();
    }

    public void go() {
        frame = new JFrame("Drawing Example");
        button = new MyButton("Draw");
        button.addActionListener(this);
        frame.getContentPane().add(button, "South");

        panel = new MyPanel();
        frame.getContentPane().add(panel, "Center");

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(360,200);
        frame.setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        if(tag == 0) {
            tag = 1;
            button.setText("Draw");
        }else {
            tag = 0;
            button.setText("Clear");
        }
        panel.repaint();
    }

    class MyButton extends JButton {
        MyButton(String text) {
            super(text);
        }

        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            g.setColor(Color.red);
            int width = getWidth();
            int height = getHeight();
            g.drawOval(4,4,width-8,height-8);
        }
    }

    class MyPanel extends JPanel {
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            if(tag == 0) {
                g.setColor(Color.blue);
                g.drawLine(40,25,30,50);
                g.setColor(Color.green);
                g.drawRect(100,50,100,46);
                g.setColor(Color.red);
                g.drawRoundRect(73,32,56,37,10,16);
                g.setColor(Color.yellow);
                g.fillOval(180,60,60,45);
                g.setColor(Color.pink);
                g.fillArc(250,32,90,60,15,30);
            }
        }
    }
}
