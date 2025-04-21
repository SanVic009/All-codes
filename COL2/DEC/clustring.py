import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.preprocessing import StandardScaler
from sklearn.cluster import KMeans, AgglomerativeClustering
from sklearn.datasets import load_iris
from scipy.cluster.hierarchy import dendrogram, linkage

# Load the dataset properly
iris = load_iris()
df = pd.DataFrame(iris.data, columns=iris.feature_names)

# Drop non-numeric or ID columns if present
df = df.select_dtypes(include=['float64', 'int64'])

# Standardize the data
scaler = StandardScaler()
scaled_data = scaler.fit_transform(df)

# -------------------------------
# K-MEANS CLUSTERING
# -------------------------------
# Determine optimal K using Elbow Method
inertia = []
for k in range(1, 11):
    kmeans = KMeans(n_clusters=k, random_state=42)
    kmeans.fit(scaled_data)
    inertia.append(kmeans.inertia_)

# Plot the elbow curve
plt.figure(figsize=(6, 4))
plt.plot(range(1, 11), inertia, marker='o')
plt.title('Elbow Method - KMeans')
plt.xlabel('Number of Clusters (k)')
plt.ylabel('Inertia')
plt.grid(True)
plt.show()

# Apply KMeans with optimal k (example: k=3)
kmeans = KMeans(n_clusters=3, random_state=42)
kmeans_labels = kmeans.fit_predict(scaled_data)
df['KMeans_Cluster'] = kmeans_labels

# -------------------------------
# HIERARCHICAL CLUSTERING
# -------------------------------
# Plot Dendrogram
linked = linkage(scaled_data, method='ward')
plt.figure(figsize=(10, 5))
dendrogram(linked)
plt.title('Dendrogram - Hierarchical Clustering')
plt.xlabel('Samples')
plt.ylabel('Distance')
plt.show()

# Apply Agglomerative Clustering (example: 3 clusters)
hc = AgglomerativeClustering(n_clusters=3)
hc_labels = hc.fit_predict(scaled_data)
df['Hierarchical_Cluster'] = hc_labels

# -------------------------------
# Visualize Clusters (using first 2 PCA features or numeric features)
plt.figure(figsize=(10, 4))

plt.subplot(1, 2, 1)
sns.scatterplot(x=scaled_data[:, 0], y=scaled_data[:, 1], hue=df['KMeans_Cluster'], palette='Set2')
plt.title('KMeans Clustering')

plt.subplot(1, 2, 2)
sns.scatterplot(x=scaled_data[:, 0], y=scaled_data[:, 1], hue=df['Hierarchical_Cluster'], palette='Set1')
plt.title('Hierarchical Clustering')

plt.tight_layout()
plt.show()
