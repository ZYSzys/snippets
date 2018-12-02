import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Vector;

public class DrawGraphics1 extends JFrame implements ActionListener,ItemListener {
    JPanel leftPanel = new JPanel();
    JPanel rightPanel = new JPanel();
    JLabel jLabel1 = new JLabel();
    JScrollPane rightJSP = new JScrollPane();
    JTextArea scratchPad = new JTextArea();
    JButton closeButton = new JButton();
    JButton clearButton = new JButton();
    JButton printButton = new JButton();
    JScrollPane leftJSP = new JScrollPane();
    Vector colors = new Vector();
    JList colorList = new JList(colors);
    JLabel penWidthLabel = new JLabel();
    JTextField penWidthDisplay = new JTextField();
    JScrollBar penWidthScrollBar = new JScrollBar();
    JCheckBox filledCheckBox = new JCheckBox();
    JPanel jdraw = new MyJPanel();
    JComboBox shapeComboBox = new JComboBox();
    int shapeTag = 0;
    int colorTag = 0;
    int filledTag = 0;

    class MyJPanel extends JPanel {
        @Override
        public void paint(Graphics g) {
            int nPoints = 3;
            int[] xPoints = {0,80,50};
            int[] yPoints = {0,50,80};

            if(filledTag == 1) {
                switch (shapeTag) {
                    case 0: {
                        g.fillRect(0,0,96,96);
                        break;
                    }
                    case 1: {
                        g.fillOval(0,0,96,96);
                        break;
                    }
                    case 2: {
                        g.fillPolygon(xPoints,yPoints,nPoints);
                        break;
                    }
                }
            }
            else {
                switch (shapeTag) {
                    case 0: {
                        g.drawRect(0,0,96,96);
                        break;
                    }
                    case 1: {
                        g.drawOval(0,0,96,96);
                        break;
                    }
                    case 2: {
                        g.drawPolygon(xPoints,yPoints,nPoints);
                        break;
                    }
                }
            }
        }
    }

    public DrawGraphics1() {
        try {
            jbInit();
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void jbInit() throws Exception {
        this.setSize(new Dimension(600,337));
        this.getContentPane().setLayout(null);
        leftPanel.setBackground(Color.white);
        leftPanel.setBounds(new Rectangle(-2,0,390,338));
        leftPanel.setLayout(null);

        this.getContentPane().setBackground(Color.red);
        this.setResizable(true);
        rightPanel.setBackground(Color.white);
        rightPanel.setBounds(new Rectangle(388,0,212,338));
        rightPanel.setLayout(null);

        jLabel1.setText("Scratch pad");
        jLabel1.setBounds(new Rectangle(12,7,78,16));
        rightJSP.setBounds(new Rectangle(12,30,167,229));

        scratchPad.setAlignmentY((float)0.5);
        scratchPad.setEditable(true);
        scratchPad.setSelectedTextColor(Color.white);
        scratchPad.setText("this is not scratch and sniff pad.");
        scratchPad.setColumns(20);
        scratchPad.setRows(8);

        closeButton.setBounds(new Rectangle(300,20,70,25));
        closeButton.setFont(new Font("MS Sans Serif",0,11));
        closeButton.setMnemonic('0');
        closeButton.setText("关闭");
        closeButton.addActionListener(new DrawGraphics1_closeButton_actionAdapter(this));
        clearButton.setBounds(new Rectangle(300,70,70,25));
        clearButton.setText("clear");
        clearButton.addActionListener(this);

        printButton.setBounds(new Rectangle(300,120,70,25));
        printButton.setText("print");

        leftJSP.setBounds(new Rectangle(5,6,65,214));

        penWidthLabel.setToolTipText("");
        penWidthLabel.setText("pen width");
        penWidthLabel.setBounds(new Rectangle(7,227,64,18));
        penWidthDisplay.setText("1");
        penWidthDisplay.setBounds(new Rectangle(280,255,86,30));
        penWidthScrollBar.setOrientation(JScrollBar.HORIZONTAL);
        penWidthScrollBar.setBounds(new Rectangle(10,255,249,30));

        filledCheckBox.setText("filled");
        filledCheckBox.setBounds(new Rectangle(302,215,70,25));
        filledCheckBox.addItemListener(new DrawGraphics1_filledCheckBox_itemAdapter(this));

        jdraw.setBounds(new Rectangle(80,10,200,200));
        jdraw.setLayout(null);

        shapeComboBox.setBounds(new Rectangle(291,160,95,28));
        shapeComboBox.addItem("方形");
        shapeComboBox.addItem("圆形");
        shapeComboBox.addItem("三角形");
        shapeComboBox.addItemListener(this);

        this.getContentPane().add(rightPanel,null);
        rightPanel.add(jLabel1,null);
        rightPanel.add(rightJSP,null);
        rightJSP.getViewport().add(scratchPad,null);

        this.getContentPane().add(leftPanel,null);
        leftPanel.add(closeButton,null);
        leftPanel.add(clearButton,null);
        leftPanel.add(printButton,null);
        leftPanel.add(leftJSP,null);
        leftPanel.add(penWidthLabel,null);
        leftPanel.add(penWidthDisplay,null);
        leftPanel.add(penWidthScrollBar,null);
        leftPanel.add(jdraw,null);
        leftPanel.add(filledCheckBox,null);
        leftPanel.add(shapeComboBox,null);
        leftJSP.getViewport().add(colorList,null);

        colors.addElement("Red");
        colors.addElement("Orange");
        colors.addElement("Yellow");
        colors.addElement("Green");
        colors.addElement("Blue");
        colors.addElement("Purple");
        colors.addElement("Black");
        colors.addElement("White");
        colorList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);

        this.setTitle("ZYSzys");
        this.setLocation(200,150);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setVisible(true);
    }

    public static void main(String[] args) {
        DrawGraphics1 drawGraphics1 = new DrawGraphics1();
    }

    void closeButton_actionPerformed(ActionEvent e) {
        System.exit(0);
    }

    @Override
    public void actionPerformed(ActionEvent e) {}

    @Override
    public void itemStateChanged(ItemEvent e) {
        if(e.getSource() instanceof JComboBox) {
            shapeTag = ((JComboBox)e.getSource()).getSelectedIndex();
            jdraw.repaint();
        }
    }

    void filledCheckBox_itemStateChanged(ItemEvent e) {
        if(filledTag == 1)
            filledTag = 0;
        else
            filledTag = 1;
    }
}

class DrawGraphics1_closeButton_actionAdapter implements ActionListener {
    DrawGraphics1 adaptee;
    DrawGraphics1_closeButton_actionAdapter(DrawGraphics1 adaptee) {
        this.adaptee = adaptee;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        adaptee.closeButton_actionPerformed(e);
    }
}

class DrawGraphics1_filledCheckBox_itemAdapter implements ItemListener {
    DrawGraphics1 adaptee;

    DrawGraphics1_filledCheckBox_itemAdapter(DrawGraphics1 adaptee) {
        this.adaptee = adaptee;
    }

    public void itemStateChanged(ItemEvent e) {
        adaptee.filledCheckBox_itemStateChanged(e);
    }
}