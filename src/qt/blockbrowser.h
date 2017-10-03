#ifndef BLOCKBROWSER_H
#define BLOCKBROWSER_H

#include "clientmodel.h"
#include "main.h"
#include "wallet.h"
#include "base58.h"
#include <QWidget>

#include <QDir>
#include <QFile>
#include <QProcess>
#include <QTime>
#include <QTimer>
#include <QStringList>
#include <QMap>
#include <QSettings>
#include <QSlider>

std::string getBlockHash(int);
std::string getBlockMerkle(int);
int getBlockNonce(int);
int getBlocknBits(int);
int getBlockTime(int);
double getBlockHardness(int);
double getBlockMint(int);

double getTxTotalValue(std::string);
double getTxFees(std::string);
std::string getInputs(std::string);
std::string getOutputs(std::string);
int64_t getInputValue(CTransaction, CScript);

int blocksInPastHours(int);
double convertCoins(int64_t);
bool addnode(std::string);
const CBlockIndex* getBlockIndex(int);
int getBlockHashrate(int);


namespace Ui {
class BlockBrowser;
}
class ClientModel;

class BlockBrowser : public QWidget
{
    Q_OBJECT

public:
    explicit BlockBrowser(QWidget *parent = 0);
    ~BlockBrowser();
    
    void setModel(ClientModel *model);
    
public slots:
    
    void blockClicked();
    void txClicked();
    void updateExplorer(bool);

private slots:

private:
    Ui::BlockBrowser *ui;
    ClientModel *model;
    
};

#endif // BLOCKBROWSER_H
