#include <cutter.h>
#include "AboutDialog.h"
#include "ui_AboutDialog.h"
#include "r_version.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & (~Qt::WindowContextHelpButtonHint));

    QString logoFile = (palette().window().color().value() < 127) ? ":/img/cutter_white_plain.svg" : ":/img/cutter_plain.svg";
    ui->logoSvgWidget->load(logoFile);

    ui->label->setText(tr("<h1>Cutter</h1>"
                          "Version " CUTTER_VERSION "<br/>"
                          "Using r2-" R2_GITTAP
                          "<h2>License</h2>"
                          "This Software is released under the GNU General Public License v3.0"
                          "<h2>Authors</h2>"
                          "xarkes, thestr4ng3r, ballessay<br/>"
                          "Based on work by Hugo Teso &lt;hugo.teso@gmail.org&gt; (originally Iaito)."));
}

AboutDialog::~AboutDialog() {}

void AboutDialog::on_buttonBox_rejected()
{
    close();
}
