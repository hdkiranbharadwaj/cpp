#include <wx/wx.h>

class TicTacToeFrame : public wxFrame {
public:
    TicTacToeFrame(const wxString& title);

private:
    wxButton* buttons[3][3];
    char board[3][3];
    bool playerTurn;  // true for 'X', false for 'O'

    void OnButtonClicked(wxCommandEvent& evt);
    void ResetBoard();
    bool CheckWin();
    bool CheckDraw();

    wxDECLARE_EVENT_TABLE();
};

enum {
    ID_BUTTON = 1000
};

wxBEGIN_EVENT_TABLE(TicTacToeFrame, wxFrame)
EVT_BUTTON(wxID_ANY, TicTacToeFrame::OnButtonClicked)
wxEND_EVENT_TABLE()

TicTacToeFrame::TicTacToeFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(300, 300)),
    playerTurn(true) {  // 'X' starts the game

    wxGridSizer* gridSizer = new wxGridSizer(3, 3, 0, 0);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            buttons[i][j] = new wxButton(this, ID_BUTTON + (i * 3 + j), "", wxDefaultPosition, wxSize(100, 100));
            gridSizer->Add(buttons[i][j], 1, wxEXPAND | wxALL);
            board[i][j] = ' ';
        }
    }

    SetSizer(gridSizer);
}

void TicTacToeFrame::OnButtonClicked(wxCommandEvent& evt) {
    int id = evt.GetId() - ID_BUTTON;
    int row = id / 3;
    int col = id % 3;

    if (board[row][col] != ' ') {
        return;  // Ignore if the cell is already occupied
    }

    // Update the board and button label with the current player's symbol
    board[row][col] = playerTurn ? 'X' : 'O';
    buttons[row][col]->SetLabel(wxString(playerTurn ? 'X' : 'O'));

    // Check for a win or a draw
    if (CheckWin()) {
        wxMessageBox(wxString::Format("Player %c wins!", playerTurn ? 'X' : 'O'), "Game Over", wxOK | wxICON_INFORMATION);
        ResetBoard();
    }
    else if (CheckDraw()) {
        wxMessageBox("It's a draw!", "Game Over", wxOK | wxICON_INFORMATION);
        ResetBoard();
    }
    else {
        playerTurn = !playerTurn;  // Switch turns after each valid move
    }
}

void TicTacToeFrame::ResetBoard() {
    playerTurn = true;  // 'X' starts the game after reset
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
            buttons[i][j]->SetLabel("");
        }
    }
}

bool TicTacToeFrame::CheckWin() {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }

    return false;
}

bool TicTacToeFrame::CheckDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

class TicTacToeApp : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(TicTacToeApp);

bool TicTacToeApp::OnInit() {
    TicTacToeFrame* frame = new TicTacToeFrame("Tic-Tac-Toe");
    frame->Show(true);
    return true;
}
