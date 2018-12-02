import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;

public class JFileChooserDemo implements ActionListener {
    JFrame frame = new JFrame("JFileChooser Demo");
    JFileChooser fc = new JFileChooser();
    JTextField tf = new JTextField();
    JButton openButton, saveButton, deleteButton;

    public static void main(String[] args) {
        JFileChooserDemo fcd = new JFileChooserDemo();
        fcd.go();
    }

    public void go() {
        //ImageIcon openIcon = new ImageIcon("open.gif");
        openButton = new JButton("Open a File...");
        saveButton = new JButton("Save a File...");
        deleteButton = new JButton("Delete a File...");

        openButton.addActionListener(this);
        saveButton.addActionListener(this);
        deleteButton.addActionListener(this);

        JPanel jp = new JPanel();
        jp.add(openButton);
        jp.add(saveButton);
        jp.add(deleteButton);

        frame.getContentPane().add(jp, BorderLayout.CENTER);
        frame.getContentPane().add(tf, BorderLayout.SOUTH);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300,200);
        frame.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        JButton button = (JButton)e.getSource();

        if(button == openButton) {
            int select = fc.showOpenDialog(frame);
            if(select == JFileChooser.APPROVE_OPTION) {
                File file = fc.getSelectedFile();
                tf.setText("Opening: " + file.getName());
            }
        }else if(button == saveButton) {
            int select = fc.showSaveDialog(frame);
            if(select == JFileChooser.APPROVE_OPTION) {
                File file = fc.getSelectedFile();
                tf.setText("Saving: " + file.getName());
            }
        }else if(button == deleteButton) {
            int select = fc.showDialog(frame, "Delete");
            if(select == JFileChooser.APPROVE_OPTION) {
                File file = fc.getSelectedFile();
                tf.setText("Deleting: " + file.getName());
            }
        }else
            tf.setText("Command cancelled");
    }
}
