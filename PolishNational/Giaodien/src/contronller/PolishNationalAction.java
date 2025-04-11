package contronller;

import view.PolishNationalView;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class PolishNationalAction implements ActionListener {
    private final PolishNationalView pn;
    @Override
    public void actionPerformed(ActionEvent e) {
        String src=e.getActionCommand();
        if(src.equals("Enter")){
            pn.ClickEnter();
        }
        else if(src.equals("Clear")){
            pn.ClickClear();
        }
    }

    public PolishNationalAction(PolishNationalView pn) {
        this.pn = pn;
    }

}
