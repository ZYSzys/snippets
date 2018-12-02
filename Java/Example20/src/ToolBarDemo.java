import oracle.jvm.hotspot.jfr.JFR;

import java.awt.*;
import java.awt.event.*;
import java.net.URL;
import javax.swing.*;

public class ToolBarDemo extends JPanel implements ActionListener {
    protected JTextArea textArea;
    protected String newline = "\n";
    static final private String OPEN = "OPEN";
    static final private String SAVE = "SAVE";
    static final private String SEARCH = "SEARCH";

    public ToolBarDemo() {
        super(new BorderLayout());

        JToolBar toolBar = new JToolBar();
        addButtons(toolBar);

        textArea = new JTextArea(15, 30);
        textArea.setEditable(false);
        JScrollPane scrollPane = new JScrollPane(textArea);

        setPreferredSize(new Dimension(450, 110));
        add(toolBar, BorderLayout.PAGE_START);
        add(scrollPane, BorderLayout.CENTER);
    }

    protected void addButtons(JToolBar toolBar) {
        JButton button = null;
        button = makeNavigationButton("1", OPEN, "打开一个文件", "打开");
        toolBar.add(button);

        button = makeNavigationButton("2", SAVE, "保存当前文件", "保存");
        toolBar.add(button);

        button = makeNavigationButton("3", SEARCH, "搜索文件中的字符", "搜索");
        toolBar.add(button);
    }

    protected JButton makeNavigationButton(String imageName, String actionCommand, String toolTipText, String altText) {
        String imgLocation = "images/"+imageName + ".jpg";
        URL imageURL = ToolBarDemo.class.getResource(imgLocation);

        JButton button = new JButton();
        button.setActionCommand(actionCommand);
        button.setToolTipText(toolTipText);
        button.addActionListener(this);

        if(imageURL != null) {
            button.setIcon(new ImageIcon(imageURL));
        }else {
            button.setText(altText);
            System.err.println("Resource not found: " + imgLocation);
        }
        return button;
    }

    public void actionPerformed(ActionEvent e) {
        String cmd = e.getActionCommand();
        String description = null;

        if(OPEN.equals(cmd)) {
            description = "Operation open";
        }else if(SAVE.equals(cmd)) {
            description = "Operation save";
        }else if(SEARCH.equals(cmd)) {
            description = "Operation search";
        }

        textArea.append("If this is real program, you will enter: " + description + newline);
    }

    public static void main(String[] args) {
        JFrame.setDefaultLookAndFeelDecorated(true);
        JFrame frame = new JFrame("ToolBarDemo");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        ToolBarDemo newContentPane = new ToolBarDemo();
        newContentPane.setOpaque(true);
        frame.setContentPane(newContentPane);

        frame.pack();
        frame.setVisible(true);
    }
}
