import Product from "./product";

function Shine() {
    const products = [
        {
            badge: "NEW",
            image: "https://cocosolis.com/bg/wp-content/uploads/aura-thumb-500x500-min-shadow.png",
            name: "AURA",
            usage: "Peptide Shimmer Spray",
            description: "Натурален блестящ спрей с пептиди за лице, тяло и коса. Озарява, хидратира и подмладява.",
            rating: 5,
            reviews: 54,
            price: "52,00 лв."
        },
        {
            image: "https://cocosolis.com/bg/wp-content/uploads/glow-thumb-500x500-min.png",
            name: "GLOW",
            usage: "Shimmer Oil",
            description: "Натурално озаряващо и хидратиращо сухо масло с блестящи частици.",
            rating: 5,
            reviews: 908,
            price: "52,00 лв."
        },
        {
            image: "https://cocosolis.com/bg/wp-content/uploads/nougat-thumb-500x500-min.png",
            name: "NOUGAT",
            usage: "Sparkling Body Butter",
            description: "Премиум грижа за кожата. Топящ се био мус. Изравнява тена и кара кожата да заблести. С аромат на вкусен крем десерт.",
            rating: 5,
            reviews: 152,
            price: "95,00 лв."
        }
    ];

    return (
        <div className="flex flex-col items-center justify-center w-screen min-h-full bg-[#FBF1EB]">
            <h2 className="text-4xl mb-2 text-center text-[#816c65] pt-16">БЛЯСЪК</h2>
            <p className="text-lg text-[#816c65] mb-10 text-center">
                Натурални продукти за елегантен блясък и грижа за кожата
            </p>

            <div className="grid grid-cols-1 sm:grid-cols-2 lg:grid-cols-3 gap-8 w-full max-w-5xl px-4">
                {products.map((product, index) => (
                    <Product
                        key={index}
                        badge={product.badge}
                        image={product.image}
                        name={product.name}
                        usage={product.usage}
                        description={product.description}
                        rating={product.rating}
                        reviews={product.reviews}
                        price={product.price}
                    />
                ))}
            </div>
        </div>
    );
}

export default Shine;
