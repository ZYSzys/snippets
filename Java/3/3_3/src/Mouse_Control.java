import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;
import java.security.Key;

public class Mouse_Control implements MouseMotionListener, KeyListener {
    JLabel label;
    JFrame frame;
    char k;
    int x, y;
    Mouse_Control() {
        JFrame.setDefaultLookAndFeelDecorated(true);

        frame = new JFrame("Mouse_Control");
        label = new JLabel("");

        frame.getContentPane().add(label, BorderLayout.SOUTH);

        frame.addMouseMotionListener(this);
        frame.addKeyListener(this);

        //frame.setLocationRelativeTo(null);
        frame.setSize(300, 300);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        while (true) {
            label.setText(k + "    X: "+ x + " Y: " + y);
        }
    }

    public static void main(String[] args)
    {
        new Mouse_Control();
    }

    @Override
    public void mouseMoved(MouseEvent e) {
        Point p = e.getLocationOnScreen();
        x = p.x;
        y = p.y;
        //label.setText(k + "    X: "+p.x+" Y: "+p.y);
    }

    public void mouseDragged(MouseEvent e) {}

    public void keyPressed(KeyEvent e) {
        if(e.getKeyCode() == KeyEvent.VK_SHIFT) {
            k = 'S';
            return;
        }
        if(e.getKeyCode() == KeyEvent.VK_CONTROL)
        {
            k = 'C';
            return;
        }
        k = 'D';
    }

    public void keyReleased(KeyEvent e) {
        k = 'U';
    }

    public void keyTyped(KeyEvent e) {}
}
