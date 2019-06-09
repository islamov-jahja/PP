using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Newtonsoft.Json;
using System.IO;
using System.Net.Http;
using System.Net;
using System.Diagnostics;

namespace lab4
{
    public partial class Form1 : Form
    {
        //private static List<String> listWithCurrency = new List<String>();

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void Exit(object sender, EventArgs e)
        {
            Task.WaitAll();
            Application.Exit();
        }

        private void DoSync(object sender, EventArgs e)
        {
            int countOfIteration = 0;
            int.TryParse(countOfIterationBar.Text, out countOfIteration);

            if (countOfIteration <= 0)
                countOfIteration = 1;

            long sumTimer = 0;
            Stopwatch timer = new Stopwatch();

            for (int i = 0; i < countOfIteration; i++)
            {
                timer.Start();
                List<String> listWithCurrencies = GetListWithCurrenciesSync();
                var allCurrencies = GetAllCurrenciesSync();
                WriteToFile(allCurrencies, listWithCurrencies);
                timer.Stop();
                timeString.Text += $"время(мс) sync: {timer.ElapsedMilliseconds}" + "\n";
                sumTimer += timer.ElapsedMilliseconds;
            }

            timeString.Text += $"среднее время(мс) sync: {sumTimer/countOfIteration}" + "\n";
        }

        private async void DoAsync(object sender, EventArgs e)
        {
            int countOfIteration;
            int.TryParse(countOfIterationBar.Text, out countOfIteration);

            if (countOfIteration <= 0)
                countOfIteration = 1;

            long sumTimer = 0;
            Stopwatch timer = new Stopwatch();

            for (int i = 0; i < countOfIteration; i++)
            {
                timer.Start();
                WriteToFileAsync(await GetAllCurrenciesAsync(), await GetListWithCurrenciesAsync());
                timer.Stop();
                timeString.Text += $"время(мс) async: {timer.ElapsedMilliseconds}" + "\n";
                sumTimer += timer.ElapsedMilliseconds;
            }

            timeString.Text += $"среднее время(мс) async: {sumTimer / countOfIteration}" + "\n";
        }

        private async Task<List<String>> GetListWithCurrenciesAsync()
        {
            try
            {
                String line;
                using (StreamReader fileWithCurrencies = new StreamReader(pathToCurrencyfile.Text))
                {
                    List<String> listWithCurrencies = new List<String>();
                    String[] arrOfLine;
                    line = await fileWithCurrencies.ReadLineAsync();
                    arrOfLine = line.Split(':');
                    return arrOfLine.ToList();
                }
            }
            catch (Exception err)
            {
                return new List<String>();
            }
        }

        private async Task<dynamic> GetAllCurrenciesAsync()
        {
            Uri BaseAddress = new Uri("https://www.cbr-xml-daily.ru/");
            HttpClient Client = new HttpClient { BaseAddress = BaseAddress };

            var response = await Client.GetAsync("daily_json.js");
            var json = response.StatusCode != HttpStatusCode.OK ? null : await response.Content.ReadAsStringAsync();
            return json == null ? null : JsonConvert.DeserializeObject(json);
        }

        private async void WriteToFileAsync(dynamic json, List<String> correctCurrencies)
        {
            String nameOfSaveFile = pathToSaveFile.Text;

            if (pathToSaveFile.Text == "")
            {
                nameOfSaveFile = "noName.txt";
            }

            StreamWriter fileToSaveData = new StreamWriter(nameOfSaveFile);
            String line;

            if (correctCurrencies.Count != 0)
            {
                foreach (var elem in json.Valute)
                {
                    foreach (String correct in correctCurrencies)
                    {
                        if (correct == Convert.ToString(elem.Value["CharCode"]))
                        {
                            line = $"{elem.Value["Nominal"]} {elem.Value["CharCode"]} по курсу {elem.Value["Value"]} руб.";
                            await fileToSaveData.WriteLineAsync(line);
                        }
                    }
                }
            }
            else
            {
                foreach (var elem in json.Valute)
                {
                    line = $"{elem.Value["Nominal"]} {elem.Value["CharCode"]} по курсу {elem.Value["Value"]} руб.";
                    await fileToSaveData.WriteLineAsync(line);
                }
            }

            fileToSaveData.Close();
        }

        private List<String> GetListWithCurrenciesSync()
        {
            try
            {
                using (StreamReader fileWithCurrencies = new StreamReader(pathToCurrencyfile.Text))
                {
                    List<String> listWithCurrencies = new List<String>();
                    String[] arrOfLine;
                    arrOfLine = fileWithCurrencies.ReadLine().Split(':');
                    return arrOfLine.ToList();
                }
            }
            catch (Exception err)
            {
                return new List<String>();
            }
        }

        private dynamic GetAllCurrenciesSync()
        {
            Uri BaseAddress = new Uri("https://www.cbr-xml-daily.ru/");
            HttpClient Client = new HttpClient { BaseAddress = BaseAddress };

            var response = Client.GetAsync("daily_json.js").Result;
            var json = response.StatusCode != HttpStatusCode.OK ? null : response.Content.ReadAsStringAsync().Result;
            return json == null ? null : JsonConvert.DeserializeObject(json);
        }

        private void WriteToFile(dynamic json, List<String> correctCurrencies)
        {
            String nameOfSaveFile = pathToSaveFile.Text;

            if (pathToSaveFile.Text == "")
            {
                nameOfSaveFile = "noName.txt";
            }

            StreamWriter fileToSaveData = new StreamWriter(nameOfSaveFile);
            String line;

            if (correctCurrencies.Count != 0)
            {
                foreach(var elem in json.Valute)
                {
                    foreach (String correct in correctCurrencies)
                    {
                        if (correct == Convert.ToString(elem.Value["CharCode"]))
                        {
                            line = $"{elem.Value["Nominal"]} {elem.Value["CharCode"]} по курсу {elem.Value["Value"]} руб.";
                            fileToSaveData.WriteLine(line);
                        }
                    }
                }
            }
            else
            {
                foreach (var elem in json.Valute)
                {
                    line = $"{elem.Value["Nominal"]} {elem.Value["CharCode"]} по курсу {elem.Value["Value"]} руб.";
                    Console.WriteLine(line);
                    fileToSaveData.WriteLine(line);
                }
            }

            fileToSaveData.Close();
        }
    }
}
