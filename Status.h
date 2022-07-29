#pragma once
#include "Levels.h"
#include "SharedVariables.h"
#include <cmath>
#include <cstdlib>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace WinGame {

	/// <summary>
	/// Summary for Status
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Status : public System::Windows::Forms::Form
	{
		Int32 showscore;
	public:
		array<RadioButton ^> ^LivesMeter;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::CheckBox^  BonusStatus;
	private: System::Windows::Forms::Label^  BonusHint;
	private: System::Windows::Forms::ProgressBar^  LevelProgress;
	private: System::Windows::Forms::Label^  BricksStatus;

	private: System::Windows::Forms::LinkLabel^  linkLabel1;

	public:	 Status(void)
		{
			InitializeComponent();
			this->
			LivesMeter = gcnew array<RadioButton ^>(10);
			showscore = 0;
	
			for(unsigned int i = 1; i <= LevelCount; i++)
				LevelList->Items->Add("Level " + i);			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Status()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  Score;
	private: System::Windows::Forms::ListBox^  LevelList;


	private: System::Windows::Forms::Label^  Lives;
	private: System::Windows::Forms::Timer^  PosAnim;
	private: System::ComponentModel::IContainer^  components;
	protected: 

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Score = (gcnew System::Windows::Forms::Label());
			this->LevelList = (gcnew System::Windows::Forms::ListBox());
			this->Lives = (gcnew System::Windows::Forms::Label());
			this->PosAnim = (gcnew System::Windows::Forms::Timer(this->components));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->BonusStatus = (gcnew System::Windows::Forms::CheckBox());
			this->BonusHint = (gcnew System::Windows::Forms::Label());
			this->LevelProgress = (gcnew System::Windows::Forms::ProgressBar());
			this->BricksStatus = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(18, 14);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(163, 55);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Score:";
			// 
			// Score
			// 
			this->Score->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->Score->Location = System::Drawing::Point(190, 14);
			this->Score->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Score->Name = L"Score";
			this->Score->Size = System::Drawing::Size(218, 57);
			this->Score->TabIndex = 1;
			this->Score->Text = L"0";
			this->Score->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// LevelList
			// 
			this->LevelList->FormattingEnabled = true;
			this->LevelList->ItemHeight = 20;
			this->LevelList->Location = System::Drawing::Point(18, 75);
			this->LevelList->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->LevelList->Name = L"LevelList";
			this->LevelList->Size = System::Drawing::Size(162, 304);
			this->LevelList->TabIndex = 2;
			this->LevelList->SelectedIndexChanged += gcnew System::EventHandler(this, &Status::LevelList_SelectedIndexChanged);
			// 
			// Lives
			// 
			this->Lives->AutoSize = true;
			this->Lives->Location = System::Drawing::Point(196, 75);
			this->Lives->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Lives->Name = L"Lives";
			this->Lives->Size = System::Drawing::Size(45, 20);
			this->Lives->TabIndex = 3;
			this->Lives->Text = L"Lives";
			// 
			// PosAnim
			// 
			this->PosAnim->Enabled = true;
			this->PosAnim->Interval = 30;
			this->PosAnim->Tick += gcnew System::EventHandler(this, &Status::PosAnim_Tick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(196, 322);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(205, 40);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Programmed by:\r\nTomáš \"Frooxius\" Mariančík";
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(196, 362);
			this->linkLabel1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(157, 20);
			this->linkLabel1->TabIndex = 5;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"patreon.com/frooxius";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Status::linkLabel1_LinkClicked);
			// 
			// BonusStatus
			// 
			this->BonusStatus->AutoSize = true;
			this->BonusStatus->Location = System::Drawing::Point(201, 132);
			this->BonusStatus->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->BonusStatus->Name = L"BonusStatus";
			this->BonusStatus->Size = System::Drawing::Size(81, 24);
			this->BonusStatus->TabIndex = 6;
			this->BonusStatus->Text = L"Bonus";
			this->BonusStatus->UseVisualStyleBackColor = true;
			// 
			// BonusHint
			// 
			this->BonusHint->AutoSize = true;
			this->BonusHint->Location = System::Drawing::Point(273, 134);
			this->BonusHint->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->BonusHint->Name = L"BonusHint";
			this->BonusHint->Size = System::Drawing::Size(96, 20);
			this->BonusHint->TabIndex = 7;
			this->BonusHint->Text = L"(Click to fire)";
			// 
			// LevelProgress
			// 
			this->LevelProgress->Location = System::Drawing::Point(201, 188);
			this->LevelProgress->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->LevelProgress->Name = L"LevelProgress";
			this->LevelProgress->Size = System::Drawing::Size(207, 23);
			this->LevelProgress->TabIndex = 8;
			// 
			// BricksStatus
			// 
			this->BricksStatus->AutoSize = true;
			this->BricksStatus->Location = System::Drawing::Point(196, 163);
			this->BricksStatus->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->BricksStatus->Name = L"BricksStatus";
			this->BricksStatus->Size = System::Drawing::Size(82, 20);
			this->BricksStatus->TabIndex = 9;
			this->BricksStatus->Text = L"Destroyed";
			// 
			// Status
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(426, 403);
			this->ControlBox = false;
			this->Controls->Add(this->BricksStatus);
			this->Controls->Add(this->LevelProgress);
			this->Controls->Add(this->BonusHint);
			this->Controls->Add(this->BonusStatus);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->Lives);
			this->Controls->Add(this->LevelList);
			this->Controls->Add(this->Score);
			this->Controls->Add(this->label1);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Status";
			this->ShowInTaskbar = false;
			this->Text = L"Status";
			this->Load += gcnew System::EventHandler(this, &Status::Status_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Status::Status_MouseDown);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Status::Status_MouseUp);
			this->Move += gcnew System::EventHandler(this, &Status::Status_Move);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Status_Load(System::Object^  sender, System::EventArgs^  e) {
					for(int i = 0; i < 10; i++)
					{
						LivesMeter[i] = gcnew RadioButton();
						LivesMeter[i]->Width = 15;
						LivesMeter[i]->Left = Lives->Left+(LivesMeter[i]->Width*i);
						LivesMeter[i]->Top = Lives->Top+Lives->Height;
						LivesMeter[i]->Checked = true;
						LivesMeter[i]->AutoCheck = false;
						LivesMeter[i]->Parent = this;
					}
			 }
private: System::Void PosAnim_Tick(System::Object^  sender, System::EventArgs^  e) {
				int x, y;
				if(this->Owner->Left + this->Owner->Width + this->Width > SystemInformation::WorkingArea.Width - 40)
					x = this->Owner->Left - this->Width - 40;
				else
					x = this->Owner->Left + this->Owner->Width + 40;

				y = this->Owner->Top;

				this->Left = this->Left*0.9 + x*0.1;
				this->Top = this->Top*0.9 + y*0.1;

				if(showscore < score)
					showscore += 10+std::rand()%( (score-showscore)/10 + 1 );

				if(showscore > score)
					showscore = score;

				Score->Text = showscore.ToString();

				BonusStatus->Checked = gotBonus;
				BonusHint->Visible = gotBonus;

				// Update level progress
				BricksStatus->Text = "Destroyed " + destroyedbricks + " of " + totalbricks + " bricks.";
				if(totalbricks > 0)
					LevelProgress->Value = ((double)destroyedbricks/totalbricks)*100;

				// Update level view
				LevelList->SelectedIndex = level;
		 }
private: System::Void linkLabel1_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
			 System::Diagnostics::Process::Start("patreon.com/frooxius");
		 }
private: System::Void Status_Move(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void Status_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		 }
private: System::Void Status_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		 }


private: System::Void LevelList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
