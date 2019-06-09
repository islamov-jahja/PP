namespace lab4
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.exitButton = new System.Windows.Forms.Button();
            this.doSyncButton = new System.Windows.Forms.Button();
            this.doAsyncButton = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.pathToCurrencyfile = new System.Windows.Forms.TextBox();
            this.pathToSaveFile = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.timeString = new System.Windows.Forms.TextBox();
            this.countOfIterationBar = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // exitButton
            // 
            this.exitButton.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.exitButton.Location = new System.Drawing.Point(477, 378);
            this.exitButton.Name = "exitButton";
            this.exitButton.Size = new System.Drawing.Size(75, 23);
            this.exitButton.TabIndex = 0;
            this.exitButton.Text = "выход";
            this.exitButton.UseVisualStyleBackColor = false;
            this.exitButton.Click += new System.EventHandler(this.Exit);
            // 
            // doSyncButton
            // 
            this.doSyncButton.Location = new System.Drawing.Point(39, 166);
            this.doSyncButton.Name = "doSyncButton";
            this.doSyncButton.Size = new System.Drawing.Size(87, 47);
            this.doSyncButton.TabIndex = 1;
            this.doSyncButton.Text = "выполнить синхронно";
            this.doSyncButton.UseVisualStyleBackColor = true;
            this.doSyncButton.Click += new System.EventHandler(this.DoSync);
            // 
            // doAsyncButton
            // 
            this.doAsyncButton.Location = new System.Drawing.Point(39, 240);
            this.doAsyncButton.Name = "doAsyncButton";
            this.doAsyncButton.Size = new System.Drawing.Size(87, 47);
            this.doAsyncButton.TabIndex = 2;
            this.doAsyncButton.Text = "выполнить асинхронно";
            this.doAsyncButton.UseVisualStyleBackColor = true;
            this.doAsyncButton.Click += new System.EventHandler(this.DoAsync);
            // 
            // label1
            // 
            this.label1.Location = new System.Drawing.Point(91, 32);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(90, 32);
            this.label1.TabIndex = 3;
            this.label1.Text = "путь до файла с валютами";
            // 
            // label2
            // 
            this.label2.Location = new System.Drawing.Point(91, 112);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(100, 32);
            this.label2.TabIndex = 4;
            this.label2.Text = "название файла сохранения";
            // 
            // pathToCurrencyfile
            // 
            this.pathToCurrencyfile.Location = new System.Drawing.Point(201, 44);
            this.pathToCurrencyfile.Name = "pathToCurrencyfile";
            this.pathToCurrencyfile.Size = new System.Drawing.Size(248, 20);
            this.pathToCurrencyfile.TabIndex = 5;
            // 
            // pathToSaveFile
            // 
            this.pathToSaveFile.Location = new System.Drawing.Point(201, 124);
            this.pathToSaveFile.Name = "pathToSaveFile";
            this.pathToSaveFile.Size = new System.Drawing.Size(248, 20);
            this.pathToSaveFile.TabIndex = 6;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(309, 166);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(30, 13);
            this.label3.TabIndex = 7;
            this.label3.Text = "Time";
            // 
            // timeString
            // 
            this.timeString.Location = new System.Drawing.Point(194, 182);
            this.timeString.Multiline = true;
            this.timeString.Name = "timeString";
            this.timeString.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.timeString.Size = new System.Drawing.Size(175, 186);
            this.timeString.TabIndex = 9;
            // 
            // textBox1
            // 
            this.countOfIterationBar.Location = new System.Drawing.Point(201, 86);
            this.countOfIterationBar.Name = "countOfIterationBar";
            this.countOfIterationBar.Size = new System.Drawing.Size(48, 20);
            this.countOfIterationBar.TabIndex = 10;
            // 
            // label4
            // 
            this.label4.Location = new System.Drawing.Point(91, 74);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(90, 32);
            this.label4.TabIndex = 11;
            this.label4.Text = "количество итераций";
            // 
            // Form1
            // 
            this.BackColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.ClientSize = new System.Drawing.Size(555, 413);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.countOfIterationBar);
            this.Controls.Add(this.timeString);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.pathToSaveFile);
            this.Controls.Add(this.pathToCurrencyfile);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.doAsyncButton);
            this.Controls.Add(this.doSyncButton);
            this.Controls.Add(this.exitButton);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Button exitButton;
        private System.Windows.Forms.Button doSyncButton;
        private System.Windows.Forms.Button doAsyncButton;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox pathToCurrencyfile;
        private System.Windows.Forms.TextBox pathToSaveFile;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox timeString;
        private System.Windows.Forms.TextBox countOfIterationBar;
        private System.Windows.Forms.Label label4;
    }
}

