import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.datasets import load_iris
from sklearn.cluster import KMeans, AgglomerativeClustering
from scipy.cluster.hierarchy import dendrogram, linkage
from sklearn.preprocessing import StandardScaler


iris = load_iris()
df = pd.DataFrame(iris.data, columns= iris.feature_names)

df = df.select_dtypes(include=['float64', 'int64'])

scaler = StandardScaler()
scaled_data = scaler.fit_transform(df)

# KNN

interita = []
for k in range(1, 11):
    kmeans = KMeans(n_clusters=k)
    kmeans.fit(scaled_data)
    interita.append(kmeans.inertia_)


plt.plot(range(1, 11), interita, marker='o')
plt.title("Elbow method - kmeans")
plt.grid(True)
plt.show()

kmeans = KMeans(n_clusters=3)
kmeans_labels = kmeans.fit_predict(scaled_data)
df['KMeans_Cluster'] = kmeans_labels


# HIERARCHICAL CLUSTERING
linked = linkage(scaled_data, method='ward')
dendrogram(linked)
plt.show()

hc = AgglomerativeClustering(n_clusters=3)
hc_labels = hc.fit_predict(scaled_data)
df['hierarchical_cluster'] = hc_labels

plt.figure(figsize=(10,5))
plt.subplot(1,2,1)
sns.scatterplot(x=scaled_data[:, 0], y=scaled_data[:, 1], hue=df['KMeans_Cluster'], palette='Set1')
plt.title("KMeans Clustering")


plt.subplot(1,2,2)
sns.scatterplot(x=scaled_data[:, 0], y=scaled_data[:, 1], hue=df['hierarchical_cluster'], palette='Set1')
plt.title("Hierarchical Clustering")

plt.tight_layout()
plt.show()

'''
things to import:
KMeans, Agglomerate
'''