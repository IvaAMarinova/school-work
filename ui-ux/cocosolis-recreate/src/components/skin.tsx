import ProductTwoSizesCard from "./product-two-sizes";
import Product from "./product";
import BigProductCard from "./big-product";

interface ProductData {
    badge?: string;
    award?: string;
    image: string;
    usage: string;
    name: string;
    description: string;
    rating: number;
    reviews: number;
    price1?: string;
    price2?: string;
    price?: string;
}

function Skin() {
    const products: ProductData[] = [
        {
            award: "https://cocosolis.com/wp-content/uploads/awards-beauty-shortlist-editors-choice.png",
            image: "https://cocosolis.com/bg/wp-content/uploads/skin-anticellulite-thumb-500x500-min.png",
            name: "Anti-cellulite Dry Oil",
            usage: "SKIN",
            description: "Анти-целулитно сухо масло. Ремоделира и оформя силуета.",
            rating: 5,
            reviews: 1266,
            price1: "45,00",
            price2: "63,00"
        },
        {
            image: "https://cocosolis.com/bg/wp-content/uploads/skin-collagenbooster-thumb-500x500-min.png",
            name: "Collagen Booster Dry Oil",
            usage: "SKIN",
            description: "Био сухо масло с натурално антиейдж действие. С масла от супер плодове.",
            rating: 5,
            reviews: 580,
            price: "45,00 лв."
        },
        {
            image: "https://cocosolis.com/bg/wp-content/uploads/skin-strech-thumb-500x500-min.png",
            name: "Stretch Mark Dry Oil",
            usage: "SKIN",
            description: "Био сухо масло против стрии. Подходящо и при дехидратирана и старееща кожа.",
            rating: 5,
            reviews: 308,
            price: "48,00 лв."
        }
    ];

    const bigProduct: ProductData = {
        image: "https://cocosolis.com/bg/wp-content/uploads/scrub-thumb-500x500-min.png",
        name: "Luxury Coffee Scrub Box",
        usage: "SCRUB",
        description: "Луксозна кутия с 4 натурални био скраба – 3 за тяло и 1 за лице.",
        rating: 5,
        reviews: 622,
        price: "48,00 лв."
    };

    return (
        <div className="flex flex-col items-center justify-center w-screen min-h-full bg-[#FBF1EB]">
            <h2 className="text-4xl mb-2 text-center text-[#816c65] pt-20">КОЖА</h2>
            <p className="text-lg text-[#816c65] mb-10 text-center">
                Серията SKIN за перфектна кожа, без несъвършенства.
            </p>

            <div className="grid grid-cols-1 sm:grid-cols-2 lg:grid-cols-3 gap-4 w-full max-w-5xl px-4">
                <ProductTwoSizesCard
                    badge={products[0].badge}
                    award={products[0].award}
                    image={products[0].image}
                    usage={products[0].usage}
                    name={products[0].name}
                    description={products[0].description}
                    rating={products[0].rating}
                    reviews={products[0].reviews}
                    price1={products[0].price1}
                    price2={products[0].price2}
                />

                {products.slice(1).map((product, index) => (
                    <Product
                        key={index}
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

            <div className="w-full max-w-5xl mt-8 px-4">
                <BigProductCard
                    image={bigProduct.image}
                    name={bigProduct.name}
                    usage={bigProduct.usage}
                    description={bigProduct.description}
                    rating={bigProduct.rating}
                    reviews={bigProduct.reviews}
                    price={bigProduct.price}
                />
            </div>
        </div>
    );
}

export default Skin;
