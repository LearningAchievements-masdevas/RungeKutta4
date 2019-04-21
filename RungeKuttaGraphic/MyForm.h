#pragma once
#include <vector>
#include <msclr\marshal_cppstd.h>
#include "RungeKutta4.h"

namespace RungeKuttaGraphic {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Button^  ButtonCalculate;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::TextBox^  textBoxFunc;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  TextBoxStartArg;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  TextBoxStartFunc;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBoxStep;
	private: System::Windows::Forms::TextBox^  textBoxCountSteps;



	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ButtonCalculate = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->textBoxFunc = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->TextBoxStartArg = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->TextBoxStartFunc = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBoxStep = (gcnew System::Windows::Forms::TextBox());
			this->textBoxCountSteps = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(554, 42);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 24);
			this->label1->TabIndex = 2;
			this->label1->Text = L"y\' = ";
			// 
			// ButtonCalculate
			// 
			this->ButtonCalculate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->ButtonCalculate->Location = System::Drawing::Point(571, 203);
			this->ButtonCalculate->Name = L"ButtonCalculate";
			this->ButtonCalculate->Size = System::Drawing::Size(140, 41);
			this->ButtonCalculate->TabIndex = 1;
			this->ButtonCalculate->Text = L"Calculate";
			this->ButtonCalculate->UseVisualStyleBackColor = true;
			this->ButtonCalculate->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(497, 458);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// textBoxFunc
			// 
			this->textBoxFunc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxFunc->Location = System::Drawing::Point(597, 39);
			this->textBoxFunc->Name = L"textBoxFunc";
			this->textBoxFunc->Size = System::Drawing::Size(135, 29);
			this->textBoxFunc->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(554, 77);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(25, 24);
			this->label2->TabIndex = 5;
			this->label2->Text = L"y(";
			// 
			// TextBoxStartArg
			// 
			this->TextBoxStartArg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->TextBoxStartArg->Location = System::Drawing::Point(585, 77);
			this->TextBoxStartArg->Name = L"TextBoxStartArg";
			this->TextBoxStartArg->Size = System::Drawing::Size(56, 29);
			this->TextBoxStartArg->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(647, 77);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(32, 24);
			this->label3->TabIndex = 7;
			this->label3->Text = L") =";
			// 
			// TextBoxStartFunc
			// 
			this->TextBoxStartFunc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->TextBoxStartFunc->Location = System::Drawing::Point(685, 77);
			this->TextBoxStartFunc->Name = L"TextBoxStartFunc";
			this->TextBoxStartFunc->Size = System::Drawing::Size(47, 29);
			this->TextBoxStartFunc->TabIndex = 8;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(558, 119);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(63, 24);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Step : ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(558, 156);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(124, 24);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Count steps : ";
			// 
			// textBoxStep
			// 
			this->textBoxStep->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxStep->Location = System::Drawing::Point(621, 119);
			this->textBoxStep->Name = L"textBoxStep";
			this->textBoxStep->Size = System::Drawing::Size(111, 29);
			this->textBoxStep->TabIndex = 11;
			// 
			// textBoxCountSteps
			// 
			this->textBoxCountSteps->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBoxCountSteps->Location = System::Drawing::Point(678, 156);
			this->textBoxCountSteps->Name = L"textBoxCountSteps";
			this->textBoxCountSteps->Size = System::Drawing::Size(54, 29);
			this->textBoxCountSteps->TabIndex = 12;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(769, 562);
			this->Controls->Add(this->textBoxCountSteps);
			this->Controls->Add(this->textBoxStep);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->TextBoxStartFunc);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->TextBoxStartArg);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBoxFunc);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ButtonCalculate);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void DrawCoords(Graphics^ gr, size_t size_x, size_t size_y) {
		size_t offset_x = size_x / 2, offset_y = size_y / 2;
		Pen^ pen = gcnew Pen(Color::Black, 2);
		System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 10);
		SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);
		float x = offset_x;
		float y = offset_y;
		gr->DrawLine(pen, Point(0, offset_y), Point(size_x, offset_y));
		gr->DrawLine(pen, Point(offset_x, 0), Point(offset_x, size_y));
		StringFormat^ drawFormat = gcnew StringFormat();
		gr->DrawString("(0, 0)", drawFont, drawBrush, x, y, drawFormat);
		gr->DrawString("(100, 0)", drawFont, drawBrush, x + 100, y, drawFormat);
		gr->DrawString("(200, 0)", drawFont, drawBrush, x + 200, y, drawFormat);
		gr->DrawString("(0, 100)", drawFont, drawBrush, x, y - 100, drawFormat);
		gr->DrawString("(0, 200)", drawFont, drawBrush, x, y - 200, drawFormat);
		gr->DrawString("(0, -100)", drawFont, drawBrush, x, y + 100, drawFormat);
		gr->DrawString("(0, -200)", drawFont, drawBrush, x, y + 200, drawFormat);
		gr->DrawString("(-100, 0)", drawFont, drawBrush, x - 100, y, drawFormat);
		gr->DrawString("(-200, 0)", drawFont, drawBrush, x - 200, y, drawFormat);
	}
	private: void DrawPoints(Graphics^ gr, size_t size_x, size_t size_y, const std::vector<MathPoint>& points) {
		Pen^ pen = gcnew Pen(Color::Blue, 2);
		size_t offset_x = size_x / 2, offset_y = size_y / 2;
		
		array< PointF >^ local = gcnew array< PointF >(points.size());
		for (size_t index = 0; index < points.size(); ++index) {
			std::cout << points[index].x << ' ' << points[index].y << '\n';
			local[index] = PointF(offset_x + points[index].x, offset_y - points[index].y);
		}
		gr->DrawCurve(pen, local);
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		size_t size_x = pictureBox1->Size.Width, size_y = pictureBox1->Size.Height;
		Bitmap^ img = gcnew Bitmap(size_x, size_y);
		Graphics^ gr = Graphics::FromImage(img);
		std::string func = msclr::interop::marshal_as<std::string>(textBoxFunc->Text);
		std::cout << "Func " << func << '\n';
		double step = Convert::ToDouble(textBoxStep->Text->Replace(".", ","));
		std::cout << "Step " << step << std::endl;
		double start_arg_value = Convert::ToDouble(TextBoxStartArg->Text->Replace(".", ","));
		std::cout << "Start arg value " << start_arg_value << std::endl;
		double start_func_value = Convert::ToDouble(TextBoxStartFunc->Text->Replace(".", ","));
		std::cout << "Start func value " << start_func_value << std::endl;
		size_t count_steps = Convert::ToInt64(textBoxCountSteps->Text);
		std::cout << "Count steps " << count_steps << std::endl;
		std::cout << step << ' ' << start_arg_value << ' ' << start_func_value << ' ' << count_steps << '\n';
		auto points = RungeKutta4(func).Calculate(step, count_steps, start_arg_value, start_func_value);
		DrawCoords(gr, size_x, size_y);
		DrawPoints(gr, size_x, size_y, points);
		pictureBox1->Image = img;
	}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	size_t size_x = pictureBox1->Size.Width, size_y = pictureBox1->Size.Height;
	Bitmap^ img = gcnew Bitmap(size_x, size_y);
	Graphics^ gr = Graphics::FromImage(img);
	DrawCoords(gr, size_x, size_y);
	pictureBox1->Image = img;
}
};
}
