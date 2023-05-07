import csv

# Define the names of the input and output files
input_file = 'allWords.csv'
output_files = {'1': 'length_1.csv', '2': 'length_2.csv', '3': 'length_3.csv', 
                '4': 'length_4.csv', '5': 'length_5.csv', '6': 'length_6.csv', 
                '7': 'length_7.csv', '8': 'length_8.csv', '9': 'length_9.csv', 
                '10': 'length_10.csv', '11': 'length_11.csv', '12': 'length_12.csv'}

# Open the input file and read each line
with open(input_file, 'r') as f:
    reader = csv.reader(f)
    for row in reader:
        word = row[0]
        length = str(len(word))

        # Check if the length of the word is valid
        if length in output_files.keys():
            # Open the corresponding output file in append mode and write the word
            with open(output_files[length], 'a') as f_out:
                writer = csv.writer(f_out)
                writer.writerow([word])