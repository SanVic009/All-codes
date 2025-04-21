import pandas as pd
from mlxtend.frequent_patterns import apriori, association_rules

# Load the data
data = pd.read_csv('C:/Users/ASUS/Desktop/Sem IV/DECL/store_data.csv', header=None)

# Convert data to one-hot encoded format
transactions = []
for i in range(len(data)):
    transactions.append([str(item) for item in data.iloc[i].dropna()])

# Create a dataframe suitable for mlxtend
from mlxtend.preprocessing import TransactionEncoder

te = TransactionEncoder()
te_data = te.fit(transactions).transform(transactions)
df = pd.DataFrame(te_data, columns=te.columns_)

# Apply Apriori Algorithm
frequent_itemsets = apriori(df, min_support=0.03, use_colnames=True)

# Generate Association Rules
rules = association_rules(frequent_itemsets, metric="lift", min_threshold=1)

# Display Results
print("Frequent Itemsets:\n", frequent_itemsets)
print("\nAssociation Rules:\n", rules[['antecedents', 'consequents', 'support', 'confidence', 'lift']])
