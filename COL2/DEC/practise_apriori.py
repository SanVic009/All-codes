import pandas as pd
from mlxtend.frequent_patterns import apriori, association_rules
from mlxtend.preprocessing import TransactionEncoder

df = pd.read_csv('')

transactions = []
for i in range(len(df)):
    transactions.append(str(items) for items in df.iloc[i].dropna())
    
tr = TransactionEncoder()
tr_data = tr.fit_transform(df)
df = pd.DataFrame(tr_data, columns= tr.columns_)

frequent_itemsets = apriori(df, min_support=0.03, use_colnames=True)

rules = association_rules(frequent_itemsets, metric='lift', min_threshold=1)

print(rules[['antecedents', 'consequents', 'confidence', 'support', 'lift']])

