import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class JDialogDemo implements ActionListener {
    JFrame frame;
    JDialog dialog;
    JButton button;

    public static void main(String[] args) {
        JDialogDemo jd = new JDialogDemo();
        jd.go();
    }

    public void go() {
        frame = new JFrame("JDialog Demo");

        dialog = new JDialog(frame, "Dialog", true);
        dialog.getContentPane().add(new JLabel("A Dialog"));
        //dialog.setSize(60, 60);

        button = new JButton("Show Dialog");
        button.addActionListener(this);

        frame.getContentPane().add(button, BorderLayout.SOUTH);
        //frame.getContentPane().add(dialog);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300,200);
        frame.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        dialog.setSize(frame.getWidth()/2, frame.getHeight()/2);
        dialog.setLocation(frame.getWidth()/4, frame.getHeight()/4);
        dialog.setVisible(true);
    }
}
