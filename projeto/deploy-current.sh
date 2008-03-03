#!/bin/bash

export GBF=/home/desenvolvimento/pjmoo-gbf/

export GBF_CURRENT=$GBF/tags/current/
export GBF_DEVELOPMENT=$GBF/trunk/projeto/

export GBF_SRC=$GBF_DEVELOPMENT/src/
export GBF_DISTRO_HEADERS=$GBF_CURRENT/include/

export WORK_DIR=/tmp/

clear
echo "Examinando Headers em desenvolvimento"
cd $GBF_SRC
ls -1 *.h > $WORK_DIR/gbf.header.development

echo "Examinando Headers em current(distro)"
cd $GBF_DISTRO_HEADERS
ls -1 *.h > $WORK_DIR/gbf.header.current

echo "Arquivos que devem ser removidos do Current são:"
cd $WORK_DIR
diff gbf.header.current gbf.header.development | grep '<'



