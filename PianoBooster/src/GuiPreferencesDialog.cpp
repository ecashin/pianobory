/*!
    @file           GuiPreferencesDialog.cpp

    @brief          xxx.

    @author         L. J. Barman

    Copyright (c)   2008, L. J. Barman, all rights reserved

    This file is part of the PianoBooster application

    PianoBooster is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    PianoBooster is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with PianoBooster.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <QtGui>

#include "GuiPreferencesDialog.h"
#include "GlView.h"

GuiPreferencesDialog::GuiPreferencesDialog(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);
    m_song = 0;
    m_settings = 0;
    m_glView = 0;
}


void GuiPreferencesDialog::init(CSong* song, QSettings* settings, CGLView * glView)
{
    m_song = song;
    m_settings = settings;
    m_glView = glView;
    displayOptimiseCheck->setChecked(m_glView->m_cfg_openGlOptimise);
}

void GuiPreferencesDialog::on_displayOptimiseCheck_toggled(bool checked)
{

}

void GuiPreferencesDialog::accept()
{
	m_glView->m_cfg_openGlOptimise = displayOptimiseCheck->isChecked();
	m_settings->setValue("display/openGlOptimise", m_glView->m_cfg_openGlOptimise );
	
	this->QDialog::accept();
}
