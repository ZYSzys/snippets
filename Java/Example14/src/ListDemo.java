import oracle.jvm.hotspot.jfr.JFR;

import java.awt.*;
import java.awt.event.*;
import javax.print.attribute.standard.DocumentName;
import javax.swing.*;
import javax.swing.JButton.*;
import javax.swing.event.*;

public class ListDemo extends JPanel implements ListSelectionListener {
    private JList list;
    private DefaultListModel listModel;
    private static final String hireString = "Add";
    private static final String fireString = "Delete";
    private JButton fireButton;
    private JTextField employeeName;
    public ListDemo() {
        super(new BorderLayout());
        listModel = new DefaultListModel();
        listModel.addElement("Alan Sommerer");
        listModel.addElement("Alison Huml");
        listModel.addElement("Kathy Walrath");
        listModel.addElement("Lisa Friendly");
        listModel.addElement("Mary Campione");
        listModel.addElement("Sharon Zakhour");

        list = new JList(listModel);
        list.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        list.setSelectedIndex(0);
        list.addListSelectionListener(this);
        list.setVisibleRowCount(5);
        JScrollPane listScrollPane = new JScrollPane(list);

        JButton hireButton = new JButton(hireString);
        HireListener hireListener = new HireListener(hireButton);
        hireButton.setActionCommand(hireString);
        hireButton.addActionListener(hireListener);
        hireButton.setEnabled(false);

        fireButton = new JButton(fireString);
        fireButton.setActionCommand(fireString);
        fireButton.addActionListener(new FireListener());

        employeeName = new JTextField(10);
        employeeName.addActionListener(hireListener);
        employeeName.getDocument().addDocumentListener(hireListener);
        String name = listModel.getElementAt(list.getSelectedIndex()).toString();

        JPanel buttonPane = new JPanel();
        buttonPane.setLayout(new BoxLayout(buttonPane, BoxLayout.LINE_AXIS));
        buttonPane.add(fireButton);
        buttonPane.add(Box.createHorizontalStrut(5));
        buttonPane.add(new JSeparator(SwingConstants.VERTICAL));
        buttonPane.add(Box.createHorizontalStrut(5));
        buttonPane.add(employeeName);
        buttonPane.add(hireButton);
        buttonPane.setBorder(BorderFactory.createEmptyBorder(5,5,5,5));

        add(listScrollPane, BorderLayout.CENTER);
        add(buttonPane, BorderLayout.PAGE_END);
    }

    class FireListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            int index = list.getSelectedIndex();
            listModel.remove(index);

            int size = listModel.getSize();

            if(size == 0){
                fireButton.setEnabled(false);
            }else {
                if(index == listModel.getSize()){
                    index--;
                }
                list.setSelectedIndex(index);
                list.ensureIndexIsVisible(index);
            }
        }
    }

    class HireListener implements ActionListener, DocumentListener {
        private boolean alreadyEnabled = false;
        private JButton button;

        public HireListener(JButton button) {
            this.button = button;
        }

        public void actionPerformed(ActionEvent e) {
            String name = employeeName.getText();

            if(name.equals("") || alreadyInList(name)) {
                Toolkit.getDefaultToolkit().beep();
                employeeName.requestFocusInWindow();
                employeeName.selectAll();
                return;
            }

            int index = list.getSelectedIndex();
            if(index == -1){
                index = 0;
            }else {
                index++;
            }

            listModel.insertElementAt(employeeName.getText(), index);

            employeeName.requestFocusInWindow();
            employeeName.setText("");

            list.setSelectedIndex(index);
            list.ensureIndexIsVisible(index);
        }

        protected boolean alreadyInList(String name) {
            return listModel.contains(name);
        }

        public void insertUpdate(DocumentEvent e) {
            enableButton();
        }

        public void removeUpdate(DocumentEvent e) {
            handleEmptyTextField(e);
        }

        public void changedUpdate(DocumentEvent e) {
            if(!handleEmptyTextField(e)) {
                enableButton();
            }
        }

        private void enableButton() {
            if(!alreadyEnabled){
                button.setEnabled(true);
            }
        }

        private boolean handleEmptyTextField(DocumentEvent e){
            if(e.getDocument().getLength() <= 0){
                button.setEnabled(false);
                alreadyEnabled = false;
                return  true;
            }
            return false;
        }
    }

    public void valueChanged(ListSelectionEvent e) {
        if(e.getValueIsAdjusting() == false){
            if(list.getSelectedIndex() == -1) {
                fireButton.setEnabled(false);
            }else{
                fireButton.setEnabled(true);
            }
        }
    }

    public static void main(String[] args) {
        JFrame.setDefaultLookAndFeelDecorated(true);

        JFrame frame = new JFrame("ListDemo");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JComponent newContentPane = new ListDemo();
        newContentPane.setOpaque(true);
        frame.setContentPane(newContentPane);

        frame.pack();
        frame.setVisible(true);
    }
}

