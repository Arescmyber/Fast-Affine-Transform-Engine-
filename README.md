# 📐 Fast Affine Transform Engine (C)

**Concept :** Algèbre linéaire et Informatique spatiale.
**Objectif :** Calculer la matrice de rotation inverse pour corriger en temps réel la dérive physique d'un dispositif optique.

**Fonctionnement :**
Au lieu d'utiliser des pièces mécaniques mobiles (gimbal), ce code utilise les mathématiques pour stabiliser une image. L'algorithme prend une dérive angulaire en entrée (lue par un gyroscope/IMU), convertit les degrés en radians, génère une matrice de rotation $2 \times 2$, et applique la transformation affine aux coordonnées cibles pour recadrer virtuellement l'affichage avec une précision micrométrique.
