import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class JComboBoxDemo
{	JFrame frame = new JFrame ("JComboBox Demo");
    JComboBox jcb1;
    JTextArea ta = new JTextArea(10,15);

    public static void main(String args[])
    {	JComboBoxDemo cbd = new JComboBoxDemo();
        cbd.go();
    }

    public void go() {
        JFrame.setDefaultLookAndFeelDecorated(true);

        JPanel p = new JPanel();
        JPanel p1 = new JPanel();
        JPanel p2 = new JPanel();
        JLabel lb1 = new JLabel("Information");
        JLabel lb2 = new JLabel("Select Name");
        JButton b = new JButton("Close");

        String[] itemList = {"Tom", "Jack", "Mary", "Linda"};
        String[] itemAttr = {" is a good boy", " is a handsome boy", " is a good girl", " is a beautiful girl"};
        jcb1 = new JComboBox(itemList);
        jcb1.setSelectedIndex(0);

        p1.setLayout(new BoxLayout(p1, BoxLayout.Y_AXIS));
        p1.add(lb2);
        p1.add(jcb1);
        p1.add(b);

        ta.setEditable(false);
        p2.setLayout(new BoxLayout(p2, BoxLayout.Y_AXIS));
        p2.add(lb1);
        p2.add(ta);

        jcb1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                ta.append(jcb1.getSelectedItem()+itemAttr[jcb1.getSelectedIndex()]+"\n");
            }
        });
        b.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        frame.setLocation(0,0);
        Container cp = frame.getContentPane();
        p.add(p2);
        p.add(p1);
        cp.add(p);

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
    }
}