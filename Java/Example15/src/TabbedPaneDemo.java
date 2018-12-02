import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.net.URL;

public class TabbedPaneDemo extends JPanel {
    public TabbedPaneDemo() {
        super(new GridLayout(1, 1));

        ImageIcon icon = createImageIcon("images/middle.gif");
        JTabbedPane tabbedPane = new JTabbedPane();

        Component p1 = makeTextPanel("First card");
        tabbedPane.addTab("One", icon, p1, "Info 1");
        tabbedPane.setSelectedIndex(0);
        Component p2 = makeTextPanel("Second card");
        tabbedPane.addTab("Two", icon, p2, "Info 2");
        Component p3 = makeTextPanel("Third card");
        tabbedPane.addTab("Three", icon, p3, "Info 3");
        Component p4 = makeTextPanel("Forth card");
        tabbedPane.addTab("Four", icon, p4, "Info 4");

        add(tabbedPane);
    }

    public static ImageIcon createImageIcon(String path) {
        URL imgURL = TabbedPaneDemo.class.getResource(path);
        if(imgURL != null){
            return new ImageIcon(imgURL);
        }else {
            System.err.println("Couldn't find file: " + path);
            return null;
        }
    }

    protected Component makeTextPanel(String text) {
        JPanel panel = new JPanel(false);
        JLabel filter = new JLabel(text);
        filter.setHorizontalAlignment(JLabel.CENTER);
        panel.setLayout(new GridLayout(1, 1));
        panel.add(filter);
        return panel;
    }

    public static void main(String[] args) {
        JFrame.setDefaultLookAndFeelDecorated(true);

        JFrame frame = new JFrame("TabbedPaneDemo");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().add(new TabbedPaneDemo(), BorderLayout.CENTER);

        frame.setSize(400, 200);
        frame.setVisible(true);
    }
}
