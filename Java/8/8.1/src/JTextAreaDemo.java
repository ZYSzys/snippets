import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.*;

public class JTextAreaDemo
{	JFrame frame = new JFrame ("JTextArea Demo");
    JTextArea ta1, ta2;
    JButton copy, clear, close;
    JLabel lb1, lb2;

    public static void main(String args[])
    {
        JTextAreaDemo tad = new JTextAreaDemo();
        tad.go();
    }

    public void go()
    {
        ta1 = new JTextArea(1,10);
        ta1.setSelectedTextColor(Color.red);
        ta2 = new JTextArea(1,10);
        ta2.setEditable(false);
        lb1 = new JLabel("Source", JLabel.LEFT);
        lb2 = new JLabel("Target", JLabel.LEFT);

        clear = new JButton("Clear");
        clear.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e)
            {
                ta1.setText("");
                ta2.setText("");
            }
        });

        copy = new JButton("Copy");
        copy.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e)
            {
                ta2.append(ta1.getText());
            }
        });

        close = new JButton("Close");
        close.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        JPanel panel1 = new JPanel();
        panel1.add(lb1);
        panel1.add(ta1);
        Border etched = BorderFactory.createEtchedBorder();
        panel1.setBorder(etched);

        JPanel panel2 = new JPanel();
        panel2.add(lb2);
        panel2.add(ta2);
        panel2.setBorder(etched);

        JPanel panel3 = new JPanel();
        panel3.add(clear);
        panel3.add(copy);
        panel3.add(close);
        panel3.setBorder(etched);

        Container cp = frame.getContentPane();
        cp.add(panel1,BorderLayout.NORTH);
        cp.add(panel2,BorderLayout.CENTER);
        cp.add(panel3,BorderLayout.SOUTH);

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
    }
}