import random
import pandas as pd

# Re-attempt to create the dataframe with entries for lab reports
lab_report_data = {
    "Lab_report_id": range(1, 51),
    "District_id": [random.randint(1, 10) for _ in range(50)],
    "Pathogen_test": [
        random.choice([None, random.randint(0, 1)]) for _ in range(50)
    ],  # 0 or 1 for test result, or None
    "Temperature_test": [
        random.randint(35, 40) for _ in range(50)
    ],  # in degrees Celsius
    "fat_contents": [
        random.choice([None, random.randint(3, 5)]) for _ in range(50)
    ],  # Fat content percentage or None
    "Protein_test": [
        random.randint(3, 5) for _ in range(50)
    ],  # Protein content percentage
    "Lactose_test": [
        random.randint(4, 7) for _ in range(50)
    ],  # Lactose content percentage
    "DNF_test": [random.randint(1, 3) for _ in range(50)],  # DNF percentage
    "Milk_type": [random.choice(["Cow", "Buffalo", "Goat"]) for _ in range(50)],
}

# Create DataFrame
df_lab_report = pd.DataFrame(lab_report_data)

# Save to CSV file
csv_file_path_lab_report = "/mnt/data/lab_report_data.csv"
df_lab_report.to_csv(csv_file_path_lab_report, index=False)

csv_file_path_lab_report
